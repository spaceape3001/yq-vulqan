////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/typedef/clock.hpp>
#include <yt/typedef/thread.hpp>
#include <functional>
#include <thread>

namespace yq::tachyon {
    class AppThread;

    class ThreadInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        ThreadInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    };
    
    struct ThreadFrame;

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
        static Thread*      current() { return s_current; }
        
        static ThreadPtr    get(ThreadID);
        static bool         valid(ThreadID);
        static Thread*      main() { return s_main; }
        static Thread*      sink() { return s_sink; }
        
        static std::vector<ThreadPtr>   all();

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
        
        using task_fn   = std::function<void()>;
        
        //! Adds a run-once task to the queue (ran on the next tick)
        void            task(task_fn&&);
        
        virtual void    owner(push_k, ThreadID) override final;
        
    protected:
        virtual Execution   tick(Context&) override final;
        
        //! This is for derived classes, in the middle of tick
        virtual Execution   subtick(Context&);
        
        // same caveats as tachyon
        ThreadData&     data();
        
        friend class AppThread;
        
        bool missing() const { return m_missing; }
        
    private:
    
        //struct Repo;
        //static Repo&    repo();
        
        struct Tack;        //< Snapshot to a tachyon (object, data, snap)
        struct Snap;
        struct Control;
        struct Inbox;
        
        friend class Tachyon;
        
        static void retain(TachyonPtr);
        static void retain(TachyonPtr, ThreadID);
        
        static void rethread(TachyonPtr, ThreadID);
        static void remove(TachyonID, ThreadID);
        
//        struct Impl;

        //using TacRepVector          = std::vector<TacRep>;
        //using SharedTacRepVector    = std::shared_ptr<TacRepVector>;
        
        using thread_map_t          = std::map<ThreadID, ThreadFrame>;
        using inbox_map_t           = std::map<ThreadID, Inbox>;
    
        void    tick(TachyonID);
        
        void    execute(Control&, Context&);
        
        struct PP {
            TachyonID   tachyon;
            ThreadID    destination;
        };
        
        
        static thread_local Thread*     s_current;
        static Thread*                  s_main;
        static Thread*                  s_sink;
        static mutex_t                  s_mutex;
        static thread_map_t             s_threads;
        static inbox_map_t              s_inboxes;
        static std::vector<TachyonPtr>  s_misfits;
        
        bool                            m_quit{ false };
        bool                            m_missing{false};
        unit::Second                    m_snooze    = 1_ms;
        std::map<TachyonID, Control>    m_objects;
        std::vector<TachyonPtr>         m_creates;  //!< Objects that were created (will be handled next tick)
        std::vector<PP>                 m_pushing;
        std::vector<task_fn>            m_tasks;
        std::thread                     m_thread;
        uint64_t                        m_tick      = 0ULL;
        time_point_t                    m_lastFrameReport{};
    };
}