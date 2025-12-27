////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>

namespace yq::tachyon {
    class PRenderMode;
    
    class IRenderMode {
        YQ_INTERFACE_DECLARE(IRenderMode, PRenderMode)
    public:
    
        virtual RenderMode      render_mode() const = 0;

        virtual bool            render_mode(disabled_k) const { return false; }
        virtual bool            render_mode(settable_k) const { return false; }
        virtual void            render_mode(set_k, RenderMode){}
        
        IRenderMode();
        virtual ~IRenderMode();
        
        static void init_meta();
    };
}
