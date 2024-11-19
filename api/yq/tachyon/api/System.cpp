////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include "Context.hpp"
#include "Execution.hpp"
#include "Post.hpp"
#include "Tachyon.hpp"
#include "Thread.hpp"

namespace yq::tachyon {

    ///////////////////////////////////////////////////////////////////////////
    //  EXECUTION CONTROL

        bool    is_specified(const Execution&es)
        {
            return !std::get_if<std::monostate>(&es);
        }

        //! Execution Modes, some will be redundant in some cases
        enum class ExecutionMode : uint8_t {
            Unspecified = 0,
        
            //! In abort mode
            Abort,
            
            //! In error mode
            Error,
            
            //! Delete this thing (Abort implied)
            Delete,
            
            //! Disabled
            Disabled,
            
            //! As previously arranged
            Continue,

            //! Temporarily stopped (whatever reason)
            Paused,
        
            //! Run once (or step for tachyons)
            Once,
            
            //! Run specified number of ticks, then delete
            Ticks,

            //! Run always (every tick)
            Always,
            
            //! Run at specified frequency
            Frequency,
            
            //! Run at specified interval (time)
            Interval,
            
            //! Run every X ticks
            Every
        };
        

        struct ExecutionControl {
            union { // union, so raw data
                unsigned int    ticks;
                unsigned int    skip;  
                double          interval;
                double          hertz;
            };
            std::error_code     ec;
            
            ExecutionMode       mode = ExecutionMode::Unspecified;
            
            ExecutionControl(){}
            ExecutionControl(const Execution& es)
            {
                set(es);
            }
            
            ExecutionControl&   operator=(const Execution& es)
            {
                set(es);
                return *this;
            }
            
            void                set(const Execution& es)
            {
                if(std::get_if<std::monostate>(&es)){
                    mode    = ExecutionMode::Unspecified;
                    return;
                }
                
                if(auto p = std::get_if<std::error_code>(&es)){
                    if(*p != std::error_code()){
                        mode    = ExecutionMode::Error;
                        ec      = *p;
                    } else {
                        mode    = ExecutionMode::Continue;
                    }
                    return;
                }
                
                if(auto p = std::get_if<bool>(&es)){
                    if(*p){
                        mode    = ExecutionMode::Continue;
                    } else {
                        mode    = ExecutionMode::Abort;
                    }
                    return;
                }
                
                if(std::get_if<abort_t>(&es)){
                    mode    = ExecutionMode::Abort;
                    return;
                }
                
                if(std::get_if<always_t>(&es)){
                    mode    = ExecutionMode::Always;
                    return;
                }
                
                if(std::get_if<continue_t>(&es)){
                    mode    = ExecutionMode::Continue;
                    return;
                }
                
                if(std::get_if<delete_t>(&es)){
                    mode    = ExecutionMode::Delete;
                    return;
                }
                
                if(std::get_if<disable_t>(&es)){
                    mode    = ExecutionMode::Disabled;
                    return;
                }
                
                if(std::get_if<error_t>(&es)){
                    mode    = ExecutionMode::Error;
                    return;
                }
                
                if(std::get_if<once_t>(&es)){
                   mode     = ExecutionMode::Once; 
                   return;
                }
                
                if(std::get_if<pause_t>(&es)){
                    mode    = ExecutionMode::Paused;
                    return;
                }
                
                if(auto p = std::get_if<unsigned>(&es)){
                    if(*p){
                        ticks   = *p;
                        mode    = ExecutionMode::Ticks;
                    } else {
                        mode    = ExecutionMode::Paused;
                    }
                    return;
                }
                
                if(auto p = std::get_if<unit::Hertz>(&es)){
                    if(*p > 0._Hz){
                        hertz   = p->value;
                        mode    = ExecutionMode::Frequency;
                    } else {
                        mode    = ExecutionMode::Paused;
                    }
                    return;
                }
                
                if(auto p = std::get_if<unit::Second>(&es)){
                    if(*p > 0._s){
                        interval    = p->value;
                        mode        = ExecutionMode::Interval;
                    } else {
                        mode    = ExecutionMode::Always;
                    }
                    return ;
                }
                
                if(auto p = std::get_if<Skip>(&es)){
                    if(p->count > 0){
                        skip        = p->count;
                        mode        = ExecutionMode::Every;
                    } else {
                        mode        = ExecutionMode::Always;
                    }
                    return;
                }
                
                //  Assert?  Maybe... still
                mode    = ExecutionMode::Error;
            }
        };
        


    ///////////////////////////////////////////////////////////////////////////
    //  REMAINDER/SORT

    struct Tachyon::Impl {
        using mutex_t       = tbb::spin_rw_mutex;
        using lock_t        = mutex_t::scoped_lock;
        
        using control_hash_t    = std::multimap<uint32_t, TachyonID>;
    
        const uint64_t          id;

        mutable mutex_t         mutex;          // used for guards
        std::vector<PostCPtr>   inbox;          //< Inbox (under mutex guard)
        std::vector<ProxyFN>    proxied;        //< Setters (under mutex guard)
        std::vector<PostCPtr>   outbox;
        std::vector<PostCPtr>   forward;
        std::vector<TachyonID>  snoops;         //!< Those eavesdropping on us
        std::vector<TachyonID>  forwards;       //!< Those we'll forward (conditionally)
        std::vector<TachyonID>  subscribers;    //!< Who we're broadcasting to
        control_hash_t          control;
        ThreadID                thread;
        uint64_t                revision        = 0;
        bool                    dirty           = false;
        
        ThreadData*             tick_data       = nullptr;
        Context*                tick_context    = nullptr;
        unsigned int            tick_thread     = 0;
        
        Impl(uint64_t i) : id(i) {};
    };
    
    
    struct Thread::Control {
        const uint64_t      id;
        TachyonPtr          object;
        
        ExecutionControl    exec;
        uint64_t            last_tick   = 0ULL;
        unit::Second        last_time   = {};
        uint64_t            next_tick   = 0ULL;
        TachyonDataPtr      last_data;
        TachyonSnapPtr      last_snap;
    };

    struct Thread::Tac {
        TachyonCPtr         object;
        TachyonDataPtr      data;
        TachyonSnapCPtr     snap;
    };


#if 0
    Execution   Tachyon::update(Context&)
    {
        return PAUSE;
    }
#endif
    
}

