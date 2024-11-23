////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <thread>

namespace yq::tachyon {

    class ThreadInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        ThreadInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Thread of something in the application
    
        \note Threads within threads on the same thread 
            is *NOT* supported.
    */
    class Thread : public Tachyon {
        YQ_TACHYON_INFO(ThreadInfo)
        YQ_TACHYON_DATA(ThreadData)
        YQ_TACHYON_SNAP(ThreadSnap)
        YQ_TACHYON_DECLARE(Thread, Tachyon)
    public:
    
        static void init_info();
        
        //  Might be NULL...
        static Thread*  current() { return s_current; }

        using Tachyon::Param;

        //! Override to do your own thing
        virtual void    run() { exec(); }
        
        //! Executes tick until quit flag
        void            exec();
        
        Thread(const Param& p = {});
        ~Thread();
        
        //! Quit demand (virtual to allow others to object)
        virtual void    quit();
        void            start();
        
        //! STALLS until thread is joined
        void            join();

        ThreadID        id() const { return ThreadID(Tachyon::id()); }
        
        //  This is the thread's tick
        virtual void    tick();
        
    protected:
        virtual Execution   tick(Context&) override;
        
        // same caveats as tachyon
        ThreadData&     data();
        
    private:
    
        struct Repo;
        static Repo&    repo();
        
        struct Tack;        //< Snapshot to a tachyon (object, data, snap)
        struct Snap;
        struct Control;
        struct Inbox;
        
        friend class Tachyon;
        
        static void retain(TachyonPtr);
        static void retain(TachyonPtr, ThreadID);
        
//        struct Impl;

        //using TacRepVector          = std::vector<TacRep>;
        //using SharedTacRepVector    = std::shared_ptr<TacRepVector>;
        
        using thread_data_map_t     = std::map<ThreadID, ThreadDataCPtr>;
        using thread_map_t          = std::map<ThreadID, ThreadPtr>;
        using inbox_map_t           = std::map<ThreadID, Inbox>;
    
        void    tick(TachyonID);
        
        void    execute(Control&, Context&);
        
        static thread_local Thread*     s_current;
        
        bool                            m_quit{ false };
        unit::Second                    m_snooze    = 1_ms;
        std::map<TachyonID, Control>    m_objects;
        std::vector<TachyonPtr>         m_creates;  //!< Objects that were created (will be handled next tick)
        std::thread                     m_thread;
        uint64_t                        m_tick      = 0ULL;
    };
}
