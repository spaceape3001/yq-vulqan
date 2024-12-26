////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector2.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition2D;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition2D {
    public:
        YQ_INTERFACE_DECLARE(IPosition2D, PPosition2D)
        
        //!  Basic position in the 2D space
        virtual Vector2D    position2d() const = 0;
        
        //!  Set position the position
        virtual void        position2d(set_k, const Vector2D&){}
        
        //virtual void        position2d(set_k, x_k, double){}
        //virtual void        position2d(set_k, y_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position2d(adjust_k, const Vector2D&){}

        //virtual void        position2d(adjust_k, x_k, double){}
        //virtual void        position2d(adjust_k, y_k, double){}

        virtual bool        position2d(disabled_k) const { return false; }
        virtual bool        position2d(settable_k) const { return false; }
        virtual bool        position2d(adjustable_k) const { return false; }

        static void init_info();
    };
}
