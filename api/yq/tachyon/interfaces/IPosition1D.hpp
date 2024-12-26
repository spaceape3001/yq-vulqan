////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector1.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition1D;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition1D {
    public:
        YQ_INTERFACE_DECLARE(IPosition1D, PPosition1D)
        
        //!  Basic position in the 1D space
        virtual Vector1D    position1d() const = 0;
        
        //!  Set position the position
        virtual void        position1d(set_k, const Vector1D&){}
        
        //virtual void        position1d(set_k, x_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position1d(adjust_t, const Vector1D&){}

        //virtual void        position1d(adjust_t, x_k, double){}

        virtual bool        position1d(disabled_t) const { return false; }
        virtual bool        position1d(settable_t) const { return false; }
        virtual bool        position1d(adjustable_t) const { return false; }

        static void init_info();
    };
}
