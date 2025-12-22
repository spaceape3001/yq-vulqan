////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/clock.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/async_task.hpp>
#include <functional>
#include <thread>

namespace yq::tachyon {
    class AppThread;
    class Application;

    class ThreadMeta : public TachyonMeta {
    public:
        template <typename C> class Writer;

        ThreadMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl=std::source_location::current());
    };
    
    struct ThreadFrame;
    class ScheduleCommand;
    class SaveRequest;
    class SaveCommand;
    class SaveReply;
    class SetOverclockCommand;
    class SetTimeCommand;
    struct ThreadSave;
    class PauseCommand;
    class ResumeCommand;

    /*! \brief Thread of something in the application
    
        \note Threads within threads on the same thread 
            is *NOT* supported.
    */
    class Thread : public Tachyon {
        YQ_TACHYON_META(ThreadMeta)
        YQ_TACHYON_DATA(ThreadData)
        YQ_TACHYON_SNAP(ThreadSnap)
        YQ_TACHYON_DECLARE(Thread, Tachyon)
    public:
    
    
        static void init_meta();
        
        //  Might be NULL...
        static Thread*      current() { return s_current; }
        
        static ThreadID     current_id();
        
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
        
        
        //  nixing for the async task (allows for futures)
        //using task_fn   = std::function<void()>;
        
        //! Adds a run-once task to the queue (ran on the next tick)
        //void            task(task_fn&&);
        
        virtual void    owner(push_k, ThreadID) override final;
        
        virtual void    shutdown();
        
        static StdThreadRevMap  standard_thread_reverse_map();
        
        static ThreadID standard(StdThread);
        
        static void     schedule(ThreadID,  AsyncTaskUPtr&&);
        static void     schedule(StdThread, AsyncTaskUPtr&&);
        
    protected:
        
        virtual Execution   tick(const Context&) override final;
        virtual Execution   teardown(const Context&) override final;
        
        //! This is for derived classes, in the middle of tick
        virtual Execution   subtick(const Context&);
        
        // same caveats as tachyon
        ThreadData&     data();
        
        friend class AppThread;
        
        bool missing() const { return m_missing; }
        
        void    snap(ThreadSnap&) const;
        void    finalize(ThreadData&) const;
        
    private:
    
        //struct Repo;
        //static Repo&    repo();
        
        struct Tack;        //< Snapshot to a tachyon (object, data, snap)
        struct Snap;
        struct Control;
        struct Inbox;
        
        friend class Tachyon;

        friend class Application;
        static void     standard(StdThread, ThreadID, bool mapRev=false);
        
        static void retain(TachyonPtr);
        static void retain(TachyonPtr, ThreadID);
        static void retain(TachyonPtr, StdThread);
        
        static void rethread(TachyonPtr, ThreadID);
        static void remove(TachyonID, ThreadID);
        
//        struct Impl;

        //using TacRepVector          = std::vector<TacRep>;
        //using SharedTacRepVector    = std::shared_ptr<TacRepVector>;
        
        using thread_map_t          = std::map<ThreadID, ThreadFrame>;
        using inbox_map_t           = std::map<ThreadID, Inbox>;
        using sthread_map_t         = std::map<StdThread, ThreadID>;
    
        void    tick(TachyonID);
        
        void    execute(Control&, const Context&);
        
        struct PP {
            TachyonID   tachyon;
            ThreadID    destination;
        };
        
        
        static thread_local Thread*     s_current;
        static Thread*                  s_main;
        static Thread*                  s_sink;
        static mutex_t                  s_mutex;
        static thread_map_t             s_threads;
        static sthread_map_t            s_sthreads;
        static inbox_map_t              s_inboxes;
        static StdThreadRevMap          s_rthreads;
        static std::vector<TachyonPtr>  s_misfits;
        
        bool                            m_quit{ false };
        bool                            m_missing{false};
        unit::Second                    m_snooze    = 1_ms;
        std::map<TachyonID, Control>    m_objects;
        std::vector<TachyonPtr>         m_creates;  //!< Objects that were created (will be handled next tick)
        std::vector<PP>                 m_pushing;
        std::vector<AsyncTaskUPtr>      m_tasks;    //< Tasks... ONLY accessed in the tick()...
        std::thread                     m_thread;
        uint64_t                        m_tick      = 0ULL;
        time_point_t                    m_lastTickTime;
        time_point_t                    m_lastFrameReport{};
        unit::Second                    m_time      = 0._s;
        unit::Second                    m_timeNew   = NAN;
        double                          m_overclock = 1.;
        bool                            m_paused    = false;
        
        void on_schedule_command(const ScheduleCommand&);
        void on_save_command(const Ref<const SaveCommand>&);
        void on_save_reply(const SaveReply&);
        void on_save_request(const Ref<const SaveRequest>&);
        void on_set_overclock_command(const SetOverclockCommand&);
        void on_set_time_command(const SetTimeCommand&);
        void on_pause_command(const PauseCommand&);
        void on_resume_command(const ResumeCommand&);
        
        template <typename Pred>
        void    foreach_child(TachyonID, Pred&&) const;
    };
}

YQ_TYPE_DECLARE(yq::tachyon::ThreadID)

