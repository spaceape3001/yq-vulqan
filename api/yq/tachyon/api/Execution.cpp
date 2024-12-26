////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Execution.hpp"

namespace yq::tachyon {

    inline bool    is_specified(const Execution&es)
    {
        return !std::get_if<std::monostate>(&es);
    }

    //! Execution Modes, some will be redundant in some cases
    enum class XIns : uint8_t {
    
        //! Unspecified
        Unspecified = 0,
    

        //! In abort mode
        Abort,
        
        //! Run always (every tick)
        Always,

        //! As previously arranged
        Continue,

        //! Delete
        Delete,
        
        //! Disable
        Disable,

        //! In error mode
        Error,
        
        //! Every number of ticks
        Every,

        //! Run at specified frequency
        Frequency,

        //! Run again in X ticks
        InCount,
        
        //! Run again in X time
        InTime,
        

        
        //! Run specified number of ticks, then delete
        Ticks,


        //! Run once (or step for tachyons)
        Once,
        
        //! Temporarily stopped (whatever reason)
        Pause,
        



        
        //! Run at specified interval (time)
        Interval,
        
        //! Run every X ticks
        Every
    };
    
    /*
    using XArg = std::variant<std::monostate, unsigned, double, unit::Second, std::error_code>;

    struct XDecode {
        XIns    mode = XIns::Unspecified;
        XArg    arg1, arg2;

        XDecode(const Execution& es)
        {
            if(std::get_if<std::monostate>(&es)){
                mode    = XIns::Unspecified;
                return;
            }
            
            if(auto p = std::get_if<std::error_code>(&es)){
                if(*p != std::error_code()){
                    mode    = XIns::Error;
                    arg1    = *p;
                } else {
                    mode    = XIns::Continue;
                }
                return;
            }
            
            if(auto p = std::get_if<bool>(&es)){
                if(*p){
                    mode    = XIns::Continue;
                } else {
                    mode    = XIns::Abort;
                }
                return;
            }
            
            if(std::get_if<abort_t>(&es)){
                mode    = XIns::Abort;
                return;
            }
            
            if(std::get_if<always_t>(&es)){
                mode    = XIns::Always;
                return;
            }
            
            if(std::get_if<continue_t>(&es)){
                mode    = XIns::Continue;
                return;
            }
            
            if(std::get_if<delete_k>(&es)){
                mode    = XIns::Delete;
                return;
            }
            
            if(std::get_if<disable_t>(&es)){
                mode    = XIns::Disabled;
                return;
            }
            
            if(std::get_if<error_t>(&es)){
                mode    = XIns::Error;
                return;
            }
            
            if(std::get_if<once_k>(&es)){
               mode     = XIns::Once; 
               return;
            }
            
            if(std::get_if<pause_t>(&es)){
                mode    = XIns::Paused;
                return;
            }
            
            if(auto p = std::get_if<unsigned>(&es)){
                if(*p){
                    ticks   = *p;
                    mode    = XIns::Ticks;
                } else {
                    mode    = XIns::Paused;
                }
                return;
            }
            
            if(auto p = std::get_if<unit::Hertz>(&es)){
                if(*p > 0._Hz){
                    hertz   = p->value;
                    mode    = XIns::Frequency;
                } else {
                    mode    = XIns::Paused;
                }
                return;
            }
            
            if(auto p = std::get_if<unit::Second>(&es)){
                if(*p > 0._s){
                    interval    = p->value;
                    mode        = XIns::Interval;
                } else {
                    mode    = XIns::Always;
                }
                return ;
            }
            
            if(auto p = std::get_if<Skip>(&es)){
                if(p->count > 0){
                    skip        = p->count;
                    mode        = XIns::Every;
                } else {
                    mode        = XIns::Always;
                }
                return;
            }
            
            //  Assert?  Maybe... still
            mode    = XIns::Error;
        }
    };
    */
}
