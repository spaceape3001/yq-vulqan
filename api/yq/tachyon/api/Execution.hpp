////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/keywords.hpp>
#include <system_error>
#include <variant>

namespace yq::tachyon {
    struct EveryTime {
        unit::Second    time;
    };
    
    constexpr EveryTime every_k::operator()(unit::Second time)
    {
        return {time};
    }
    
    struct EveryCount {
        unsigned count;
    };

    constexpr EveryCount every_k::operator()(unsigned count)
    {
        return { count };
    }
    
    struct OnceTime {
        unit::Second    time;
    };
    
    constexpr OnceTime operator,(once_k, unit::Second time)
    {
        return { time };
    }
    
    struct OnceCount {
        unsigned count;
    };

    constexpr OnceCount operator,(once_k, unsigned count)
    {
        return { count };
    }

    struct ForTime {
        unit::Second    time;
    };
    
    constexpr ForTime operator,(for_k, unit::Second time)
    {
        return { time };
    }
    
    struct ForTimeAt {
        unit::Second    time;
        unit::Second    Δt;
    };
    
    constexpr ForTimeAt operator,(ForTime ft, unit::Second Δt)
    {
        return { ft.time,  Δt};
    }
    
    struct ForCount {
        unsigned count;
    };
    
    constexpr ForCount operator,(for_k, unsigned count)
    {
        return { count };
    }
    
    struct ForCountAt {
        unsigned count;
        unsigned Δt;
    };
    
    constexpr ForCountAt operator,(ForCount fc, unsigned Δt)
    {
        return { fc.count, Δt };
    }
    
    
    
    /*! \brief Execution Control
    
        This is a simple variant that controls how a task gets controlled.  
        It can be initial or altered at runtime.
        
        std::monostate      Continues as previous scheduled.
        std::error_code     An error, the task will terminate, otherwise continues as previously scheduled 
        bool                FALSE will abort, TRUE will continue as previously scheduled
        always_t            Task will be executed EVERY frame
        once_t              Task will be executed ONCE (or once more), next available tick
        unsigned            Task will be executed X times (or update the count remaining) at present update rate
        Hertz               Task will be executed at specified frequency (good for those needing more ticks, but not every tick)
        Second              Task will be executed in X seconds (good for slow/recurring)
        Skip                Task will be executed, repeatedly, every X times
    */
    using Execution     = std::variant<
        std::monostate,     //< Unspecified (ie, don't change, implicit continue)
        std::error_code,    //< Error occured (ie, becomes "ABORT" if not empty)
        bool,               //< TRUE/FALSE (continue/abort)
        abort_k,            //< Abort
        always_k,           //< Always run (will be the default)         
        continue_k,         //< Continue
        delete_k,           //< Delete
        disable_k,          //< Disable
        error_k,            //< Error occured (ie abort)
        once_k,             //< Execute once, auto-stop
        pause_k,            //< Pause
        stop_k,             //< Stop (functionally the same as Pause)
        unsigned,           //< Again in X ticks
        unit::Hertz,        //< At rate
        unit::Second,       //< Again in X time
        EveryTime,          //< Every X time
        EveryCount,         //< Every X ticks
        OnceTime,           //< Once more in X time
        OnceCount,          //< Once more in X ticks
        ForTime,            //< For X time, every tick
        ForTimeAt,          //< For X time, at specified interval
        ForCount,           //< For X ticks at specified interval
        ForCountAt          //< For X ticks at specified interval
    >;
    
}
