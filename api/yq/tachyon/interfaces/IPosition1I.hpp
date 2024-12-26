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
    class PPosition1I;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition1I {
    public:
        YQ_INTERFACE_DECLARE(IPosition1I, PPosition1I)
        
        //!  Basic position in the 1I space
        virtual Vector1I    position1i() const = 0;
        
        //!  Set position the position
        virtual void        position1i(set_k, const Vector1I&){}
        
        //virtual void        position1i(set_k, x_k, int){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position1i(adjust_k, const Vector1I&){}

        //virtual void        position1i(adjust_k, x_k, int){}

        virtual bool        position1i(disabled_k) const { return false; }
        virtual bool        position1i(settable_k) const { return false; }
        virtual bool        position1i(adjustable_k) const { return false; }

        static void init_info();
    };
}
