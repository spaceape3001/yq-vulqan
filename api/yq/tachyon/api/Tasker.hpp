////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <tbb/spin_rw_mutex.h>
#include <atomic>
#include <deque>
#include <map>
#include <thread>
#include <source_location>

namespace yq::tachyon {

    /*! This is a thread pool for asynchronous (& possibly long) tasks
    
        \note This is for "outside" usual thread tasking, though, we'll retain
        the current frame for the task's benefit.
        
        It'll always keep one "janitor" type of thread running, and one "worker" 
        thread running until exit.  If there's multiple idle threads, then they
        will eventually be spun down (in accordance to the idle_kill threshhold).
        
        TODO: Expirations, Priorities, etc
    */
    class Tasker {
    public:

        static size_t  max_thread_recommended();

        struct Task;
        using TaskSPtr  = std::shared_ptr<Task>;
    
        struct Param {
        
            //! Max threads, zero will default to semi-reasonable; note the keeper thread is separate
            size_t              max_threads = 0;
            
            //! Interval to check for new tasks
            unit::Nanosecond    check_interval  = 1000._µs;
            
            //! Interval to kill an idle task thread
            unit::Nanosecond    idle_kill   = 1._s;
        };
    
        //! Constructor
        Tasker();

        Tasker(const Param&);

        ~Tasker();
        
        void    cancel_all();

        void    schedule(TaskSPtr&&, const std::source_location& sl=std::source_location::current());

        template <typename Pred>
        auto    simple_task(Pred&&, const std::source_location& sl=std::source_location::current());
        
        size_t  pending_count() const;
        
        // Count of worker threads
        size_t  worker_thread_count() const;
        size_t  idle_worker_count() const;
        
        bool    no_worker_threads() const;

        struct Stats {
            size_t  workers = 0;
            size_t  idle    = 0;
            size_t  pending = 0;
        };

        Stats   statistics() const;

    private:

        template <typename Pred> struct SimpleTask;   
        template <typename T, typename Pred> struct PromiseTask;
        
        
        enum {
            Running = 0,
            Clearing,
            Quitting
        };
        
        struct TData {
            bool        dead = false;
            bool        done = false;
            size_t      id;
            TaskSPtr    task;
            std::thread thread;
            bool        quit    = false;
        };
        
        
        mutable tbb::spin_rw_mutex      m_mutex;
        std::map<size_t,TData>          m_threads;
        std::deque<TaskSPtr>            m_tasks;
        std::thread                     m_keeper;
        const unit::Nanosecond          m_checkInterval;
        const unit::Nanosecond          m_idleKill;               
        const size_t                    m_maxThreads;
        int                             m_state = Running;  // atomic would be nice... fetch_max ain't yet supported...
        
        
        bool        cancelling() const;
        bool        quitting() const;
        
        void        keeper_task();
        void        worker_task(size_t);
        void        create_worker();
        TaskSPtr    take_task();
        
    };
    
}
