////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class PPosition2M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition2M {
    public:
        YQ_INTERFACE_DECLARE(IPosition2M, PPosition2M)
        
        //!  Basic position in the 2M space
        virtual Vector2M    position2m() const = 0;
        
        //!  Set position the position
        virtual void        position2m(set_t, const Vector2M&){}
        
        //virtual void        position2m(set_t, x_t, Meter){}
        //virtual void        position2m(set_t, y_t, Meter){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position2m(adjust_t, const Vector2M&){}

        //virtual void        position2m(adjust_t, x_t, Meter){}
        //virtual void        position2m(adjust_t, y_t, Meter){}

        virtual bool        position2m(disabled_t) const { return false; }
        virtual bool        position2m(settable_t) const { return false; }
        virtual bool        position2m(adjustable_t) const { return false; }

        static void init_info();
    };
}
