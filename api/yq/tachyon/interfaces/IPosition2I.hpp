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
    class PPosition2I;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition2I {
    public:
        YQ_INTERFACE_DECLARE(IPosition2I, PPosition2I)
        
        //!  Basic position in the 2I space
        virtual Vector2I        position2i() const = 0;
        
        //!  Set position the position
        virtual void            position2i(set_t, const Vector2I&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position2i(move_t, const Vector2I&){}
        
        virtual bool            position2i(disabled_t) const { return false; }
        virtual bool            position2i(settable_t) const { return false; }

        static void init_info();
    };
}
