////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Thread.hpp"
#include "ThreadData.hpp"
#include "ThreadInfoWriter.hpp"

namespace yq::tachyon {

    struct Thread::Tac {
        TachyonPtr          object;
        TachyonDataCPtr     data;
        TachyonSnapCPtr     snap;
    };

    ThreadInfo::ThreadInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
    }

    struct Thread::Repo {
        using mutex_t   = tbb::spin_rw_mutex;
        using lock_t    = mutex_t::scoped_lock;
        
        mutable mutex_t                     mutex;
        std::map<ThreadID, ThreadDataCPtr>  data;
        
        // Might not be perfect....
        std::vector<ThreadDataCPtr>         current() const
        {
            std::vector<ThreadDataCPtr> ret;
            {
                lock_t  _lock(mutex, false);
                ret.reserve(data.size());
                for(auto& i : data){
                    if(i.second)
                        ret.push_back(i);
                }
            }
            return ret;
        }
        
        void    nix(ThreadID tid)
        {
            ThreadDataCPtr  old;
            {
                lock_t  _lock(mutex, true);
                auto i = data.find(tid);
                if(i != data.end()){
                    std::swap(old, i.second);
                    data.erase(i);
                }
            }
        }
    };
    
    Thread::Repo&   Thread::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    Thread::Thread(const Param& p) : Tachyon(p, THREAD)
    {
    }
    
    Thread::~Thread()
    {
        repo().nix(id());
    }
    
    void Thread::check()
    {
    }
    
    void Thread::cmd_start()
    {
        
    }
    
    void Thread::cmd_quit()
    {
        m_quit      = true;
    }
    
    void Thread::exec()
    {
        while(!m_quit){
            check();
        }
    }
    
    ThreadDataPtr Thread::tick(Context&ctx)
    {
        TachyonDataPtr      tacData = Tachyon::tick(ctx);
        ThreadDataPtr       tdp = static_cast<ThreadData*>(tacData.ptr());
        
        
    }
    
    void Thread::init_info()
    {
        auto w = writer<Thread>();
        w.description("Thread");
    }

}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Thread)
