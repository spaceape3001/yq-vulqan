////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tasker.hxx"
#include <yq/tachyon/api/Frame.hpp>
#include <chrono>

namespace yq::tachyon {
    #define LOCK tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, false);
    #define WLOCK tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, true);
    
    size_t  Tasker::max_thread_recommended()
    {
        //  Note... upper limit can be revisited, nothing special 
        //  (Aside from it's N-2 on an AMD 7995WX.)
        return std::clamp<size_t>(std::thread::hardware_concurrency(), 2, 190);
    }
    
    Tasker::Tasker() : Tasker(Param())
    {
    }

    Tasker::Tasker(const Param&p) : 
        m_checkInterval(p.check_interval), 
        m_idleKill(p.idle_kill),
        m_maxThreads(p.max_threads ? p.max_threads : max_thread_recommended()),
        m_state{Running}
    {
    
        m_keeper    = std::thread([this](){
            this->keeper_task();
        });
    }

    Tasker::~Tasker()
    {
        {
            WLOCK
            m_state = Quitting;
        }
        m_keeper.join();
    }

    void Tasker::cancel_all()
    {
        std::deque<TaskSPtr>    tasks;
        
        {
            WLOCK
            m_state = Clearing;
            std::swap(m_tasks, tasks);
        }
        
        for(auto& task : tasks)
            task->cancelled();
    }

    bool Tasker::cancelling() const
    {
        LOCK
        return m_state >= Clearing;
    }

    void Tasker::create_worker()
    {
        static std::atomic<size_t>  s_next{1};
    
        size_t  id  = s_next++;

        WLOCK
        m_threads[id] = TData{
            .id = id,
            .thread = std::thread([id,this](){
                this->worker_task(id);
            })
        };
    }

    size_t  Tasker::idle_worker_count() const
    {
        size_t  ret = 0;
        LOCK
        for(auto& wt : m_threads){
            if(!wt.second.task)
                ++ret;
        }
        return ret;
    }

    void Tasker::keeper_task()
    {
        for(;;){
            size_t  remaining = 0;
            size_t  killed    = 0;
            
            {
                std::vector<TaskSPtr>   dead;   // shouldn't be necessary, but just in case
                {
                    WLOCK
                    for(auto itr = m_threads.begin(); itr != m_threads.end();){
                        if(itr->second.done && !itr->second.dead){
                            if(itr->second.task)
                                dead.push_back(itr->second.task);
                            itr->second.thread.join();
                            ++killed;
                            itr = m_threads.erase(itr);
                        } else {
                            ++itr;
                            ++remaining;
                        }
                    }
                }
            }
            
            if(quitting()){
                if(remaining)
                    continue;
                break;
            }
            
            if(cancelling()){
                if(remaining)
                    continue;

                WLOCK
                m_state = Running;
                continue;
            }
            
            Stats   stats   = statistics();
            if(stats.workers < m_maxThreads){
                if((stats.workers == 0) || (stats.idle == 0)){  
                    // want at least one idle unless full
                    create_worker();
                }
            }
            
            std::this_thread::sleep_for(std::chrono::nanoseconds((long) m_checkInterval.value));
        }
    }

    bool    Tasker::no_worker_threads() const
    {
        LOCK
        return m_threads.empty();
    }
    
    size_t  Tasker::pending_count() const
    {
        LOCK
        return m_tasks.size();
    }
    
    bool        Tasker::quitting() const
    {
        LOCK
        return m_state == Quitting;
    }
    
    void Tasker::schedule(TaskSPtr&& task, const std::source_location& sl)
    {
        if(!task)   
            return;
        if(cancelling())
            return;
            
        task->m_frame       = Frame::current();
        task->m_location    = sl;
        WLOCK
        m_tasks.push_back(std::move(task));
    }

    Tasker::Stats    Tasker::statistics() const
    {
        Stats ret;
        {
            LOCK
            ret.pending = m_tasks.size();
            for(auto& th : m_threads){
                if(!th.second.done)
                    ++ret.workers;
                if(!th.second.task)
                    ++ret.idle;
            }
        }
        return ret;
    }

    Tasker::TaskSPtr    Tasker::take_task()
    {
        WLOCK
        if(m_tasks.empty())
            return {};
        TaskSPtr    ret = m_tasks.front();
        m_tasks.pop_front();
        return ret;
    }


    void Tasker::worker_task(size_t id)
    {
        auto    t0  = std::chrono::high_resolution_clock::now();
        while(!cancelling())
        {
            {
                LOCK
                if(m_threads[id].quit)
                    break;
            }
        
            TaskSPtr    task    = take_task();
            if(task){
                {
                    WLOCK
                    m_threads[id].task  = task;
                }
                Frame::s_current  = task->m_frame.ptr();
                // TODO: eventually metrics....? ... maybe a capture routine?
                task->execute();
                Frame::s_current = nullptr;
                {
                    WLOCK
                    m_threads[id].task  = {};
                }
            }
            
            auto t  = std::chrono::high_resolution_clock::now();
            if(task){
                t0  = t;
                continue;
            }
            
            if(std::chrono::nanoseconds(t - t0).count() >= m_idleKill.value){
                if(idle_worker_count() > 1)
                    break;
            }
            
            std::this_thread::sleep_for(std::chrono::nanoseconds((long) m_checkInterval.value));
        }
        
        WLOCK
        m_threads[id].done   = true;
    }

    size_t  Tasker::worker_thread_count() const
    {
        LOCK
        return m_threads.size();
    }
}
