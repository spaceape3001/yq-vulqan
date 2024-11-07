////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Thread.hpp"
#include "ThreadInfoWriter.hpp"

namespace yq::tachyon {
    ThreadInfo::ThreadInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
    }

    Thread::Thread(const Param& p) : Tachyon(p, THREAD)
    {
    }
    
    Thread::~Thread()
    {
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
    
    void Thread::init_info()
    {
        auto w = writer<Thread>();
        w.description("Thread");
    }

}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Thread)
