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
    struct Skip {
        unsigned count = 1; // number to skip, so 1 is every other time, 2 is every third time, etc...
    };
    
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
        abort_t,            //< Abort
        always_t,           //< Always run (will be the default)         
        continue_t,         //< Continue
        delete_t,           //< Delete
        disable_t,          //< Disable
        error_t,            //< Error occured (ie abort)
        once_t,             //< Execute once, auto-drop
        pause_t,            //< Pause
        unsigned, 
        unit::Hertz, 
        unit::Second, 
        Skip
    >;
    
}
