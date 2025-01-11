////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Size2.hpp>
#include <yt/keywords.hpp>
#include <yt/api/Interface.hpp>

namespace yq::tachyon {
    class PSize²;

    //! Interface for a single object size
    //! \note Inheritance is not permissible here
    class ISize² {
    public:
        YQ_INTERFACE_DECLARE(ISize², PSize²)
        
        //!  Basic size in the 2I space
        virtual Size2D      size() const = 0;
        
        //!  Set size the size
        virtual void        size(set_k, const Size2I&){}
        
        //!  Move the size (ie set to size + delta)
        virtual void        size(adjust_k, const Size2I&){}

        virtual bool        size(disabled_k) const { return false; }
        virtual bool        size(settable_k) const { return false; }
        virtual bool        size(adjustable_k) const { return false; }

        static void init_info();
    };
}
