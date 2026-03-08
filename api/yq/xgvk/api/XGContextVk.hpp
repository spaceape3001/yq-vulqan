////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xg/XGContext.hpp>

namespace yq::tachyon {
    struct XGContextVk : public XGContext {
    
        //! Use to finish tearing (US) down
        bool    tear_finished    = false;

        //! Use to start tearing down 
        bool    tear_request     = false;
        
        //! Use to start ticking ... only valid during setup
        bool    tick_request     = false;
        
    
        XGContextVk();
        virtual ~XGContextVk();
    };
}
