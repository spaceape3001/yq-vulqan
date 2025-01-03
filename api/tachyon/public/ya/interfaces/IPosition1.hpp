////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector1.hpp>
#include <yt/keywords.hpp>
#include <yt/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition¹;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition¹ {
    public:
        YQ_INTERFACE_DECLARE(IPosition¹, PPosition¹)
        
        //!  Basic position in the 1D space
        virtual Vector1D    position() const = 0;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector1D&){}
        virtual void        position(set_k, x_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(move_k, const Vector1D&Δ){}
        virtual void        position(move_k, x_k, double Δx){}

        virtual bool        position(disabled_k) const { return false; }
        virtual bool        position(settable_k) const { return false; }
        virtual bool        position(moveable_k) const { return false; }

        static void init_info();
    };
}
