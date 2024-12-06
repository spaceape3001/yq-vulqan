////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {
    class PPosition1M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition1M {
    public:
        YQ_INTERFACE_DECLARE(IPosition1M, PPosition1M)
        
        //!  Basic position in the 1M space
        virtual Vector1M    position1m() const = 0;
        
        //!  Set position the position
        virtual void        position1m(set_t, const Vector1M&){}
        
        //virtual void        position1m(set_t, x_t, Meter){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position1m(adjust_t, const Vector1M&){}

        //virtual void        position1m(adjust_t, x_t, Meter){}

        virtual bool        position1m(disabled_t) const { return false; }
        virtual bool        position1m(settable_t) const { return false; }
        virtual bool        position1m(adjustable_t) const { return false; }

        static void init_info();
    };
}
