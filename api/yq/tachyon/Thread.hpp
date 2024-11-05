////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBX.hpp>
#include <yq/tachyon/Tachyon.hpp>
#include <thread>

namespace yq::tachyon {

    class ThreadInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        ThreadInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Thread of something in the application
    */
    class Thread : public Tachyon {
        YQ_OBJECT_INFO(ThreadInfo)
        YQ_OBJECT_DECLARE(Thread, Tachyon)
    public:
    
        static void init_info();

        using Tachyon::Param;

        //! Override to do your own thing
        virtual void    run() { exec(); }
        
        //! Executes check until quit flag
        void            exec();
        virtual void    check();
        
        static Thread&  current();

        Thread(const Param& p = {});
        ~Thread();
        
        void            cmd_quit();
        void            cmd_start();
        
    private:
    
        struct Repo;
        static Repo&    repo();
    
        std::atomic<bool>       m_quit{ false };
        unit::Second            m_snooze    = 1_ms;
        std::vector<Tachyon*>   m_objects;
        std::thread             m_thread;
    };
}
