////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/pipeline/DrawMode.hpp>

namespace yq::tachyon {
    class PDrawMode;
    
    class IDrawMode {
        YQ_INTERFACE_DECLARE(IDrawMode, PDrawMode)
    public:
    
        virtual DrawMode    draw_mode() const = 0;
        virtual DrawMode    draw_mode(use_k) const { return draw_mode(); }

        virtual bool        draw_mode(disabled_k) const { return false; }
        virtual bool        draw_mode(settable_k) const { return false; }
        virtual void        draw_mode(set_k, DrawMode){}
        
        IDrawMode();
        virtual ~IDrawMode();
        
        static void init_meta();
    };
}
