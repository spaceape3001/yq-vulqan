////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size1.hpp>
#include <yq/vector/Vector1.hpp>
#include <yt/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PSize¹;

    //! Interface for a single object size
    //! \note Inheritance is not permissible here
    class ISize¹ {
    public:
        YQ_INTERFACE_DECLARE(ISize¹, PSize¹)
        
        //!  Basic size in the 1I space
        virtual Size1D      size() const = 0;
        
        //!  Set size the size
        virtual void        size(set_k, const Size1D&){}
        virtual void        size(set_k, x_k, double){}
        
        //!  Move the size (ie set to size + delta)
        virtual void        size(add_k, const Vector1D&){}
        virtual void        size(add_k, x_k, double){}

        virtual void        size(multiply_k, double){}
        virtual void        size(multiply_k, const Vector1D&){}
        virtual void        size(multiply_k, x_k, double){}
        
        virtual bool        size(disabled_k) const { return false; }
        virtual bool        size(settable_k) const { return false; }
        virtual bool        size(addable_k) const { return false; }
        virtual bool        size(multipliable_k) const { return false; }

        static void init_info();
    };
}

