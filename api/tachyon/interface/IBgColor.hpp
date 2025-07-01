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
    class PBgColor;
    
    /*! \brief Interface for background or a secondary/alternate color
    */
    class IBgColor {
        YQ_INTERFACE_DECLARE(IBgColor, PBgColor)
    public:
    
        virtual RGBA4F  bgcolor() const = 0;

        virtual bool    bgcolor(disabled_k) const { return false; }
        virtual bool    bgcolor(settable_k) const { return false; }
        
        virtual void    bgcolor(set_k, const RGBA4F&){}
        
        IBgColor();
        virtual ~IBgColor();
        
        static void init_meta();
    };
}
