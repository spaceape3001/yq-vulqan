////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Size2.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PSize2I;

    //! Interface for a single object size
    //! \note Inheritance is not permissible here
    class ISize2I {
    public:
        YQ_INTERFACE_DECLARE(ISize2I, PSize2I)
        
        //!  Basic size in the 2I space
        virtual Size2I      size2i() const = 0;
        
        //!  Set size the size
        virtual void        size2i(set_k, const Size2I&){}
        
        //!  Move the size (ie set to size + delta)
        virtual void        size2i(adjust_k, const Size2I&){}

        virtual bool        size2i(disabled_k) const { return false; }
        virtual bool        size2i(settable_k) const { return false; }
        virtual bool        size2i(adjustable_k) const { return false; }

        static void init_info();
    };
}
