////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>
#include <yq/typedef/rgba.hpp>

namespace yq::tachyon {
    class PColor;
    
    class IColor {
    public:
        YQ_INTERFACE_DECLARE(IColor, PColor)
    
        virtual RGBA4F  color() const = 0;

        virtual bool    color(disabled_k) const { return false; }
        virtual bool    color(settable_k) const { return false; }
        
        virtual void    color(set_k, const RGBA4F&){}
        
        IColor();
        virtual ~IColor();
        
        static void init_info();
    };
}
