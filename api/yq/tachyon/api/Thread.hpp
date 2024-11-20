////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
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
        
        //! Executes tick until quit flag
        void            exec();
        
        static Thread&  current();

        Thread(const Param& p = {});
        ~Thread();
        
        virtual void    quit();
        virtual void    start();

        ThreadID        id() const { return ThreadID(Tachyon::id()); }
        
        //  This is the thread's tick
        virtual void        tick();
        
    protected:
        virtual void        tick(Context&) override {}
        
    private:
    
        struct Repo;
        static Repo&    repo();
        
        struct Mini;
        struct Control;
        struct Impl;
    
    
        void    tick(TachyonID);
    
        std::atomic<bool>           m_quit{ false };
        unit::Second                m_snooze    = 1_ms;
        std::map<TachyonID, Tac>    m_objects;
        std::thread                 m_thread;
    };
}
