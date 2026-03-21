////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PScreenScaleM;

    //! Interface for a single object screen_scale
    //! \note Inheritance is not permissible here
    class IScreenScaleM {
    public:
        YQ_INTERFACE_DECLARE(IScreenScaleM, PScreenScaleM)
        
        virtual Meter       screen_scale() const = 0;
        
        virtual void        screen_scale(set_k, Meter){}
        
        virtual void        screen_scale(add_k, Meter Δ){}

        virtual void        screen_scale(multiply_k, double){}

        virtual bool        screen_scale(disabled_k) const { return false; }
        virtual bool        screen_scale(settable_k) const { return false; }
        virtual bool        screen_scale(addable_k) const { return false; }
        virtual bool        screen_scale(multipliable_k) const { return false; }

        static void init_meta();
    };
}
