////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class Frame;
    
    struct Context {
        //! Previous tick
        const Frame&    frame;
        //! Our expected tick time delta
        unit::Second    Δt      = { 0. };
        
        Context(){}
        Context(Context& cp) : frame(cp.frame), Δt(cp.Δt) {}
    };
    
}
