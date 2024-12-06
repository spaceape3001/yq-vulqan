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
        virtual void        position1i(set_t, const Vector1I&){}
        
        //virtual void        position1i(set_t, x_t, int){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position1i(adjust_t, const Vector1I&){}

        //virtual void        position1i(adjust_t, x_t, int){}

        virtual bool        position1i(disabled_t) const { return false; }
        virtual bool        position1i(settable_t) const { return false; }
        virtual bool        position1i(adjustable_t) const { return false; }

        static void init_info();
    };
}
