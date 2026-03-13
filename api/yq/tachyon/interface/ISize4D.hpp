////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/typedef/size4.hpp>
#include <yq/typedef/vector4.hpp>

namespace yq::tachyon {
    class PSize⁴D;

    //! Interface for a single object size
    //! \note Inheritance is not permissible here
    class ISize⁴D {
    public:
        YQ_INTERFACE_DECLARE(ISize⁴D, PSize⁴D)
        
        //!  Basic size in the 4I space
        virtual Size4D      size() const = 0;
        
        //!  Set size the size
        virtual void        size(set_k, const Size4D&){}
        virtual void        size(set_k, x_k, double){}
        virtual void        size(set_k, y_k, double){}
        virtual void        size(set_k, z_k, double){}
        virtual void        size(set_k, w_k, double){}
        
        //!  Move the size (ie set to size + delta)
        virtual void        size(add_k, const Size4D&){}
        void                size(add_k, const Vector4D&);
        virtual void        size(add_k, x_k, double){}
        virtual void        size(add_k, y_k, double){}
        virtual void        size(add_k, z_k, double){}
        virtual void        size(add_k, w_k, double){}

        virtual void        size(multiply_k, double){}
        virtual void        size(multiply_k, const Vector4D&){}
        virtual void        size(multiply_k, x_k, double){}
        virtual void        size(multiply_k, y_k, double){}
        virtual void        size(multiply_k, z_k, double){}
        virtual void        size(multiply_k, w_k, double){}
        
        virtual bool        size(disabled_k) const { return false; }
        virtual bool        size(settable_k) const { return false; }
        virtual bool        size(addable_k) const { return false; }
        virtual bool        size(multipliable_k) const { return false; }

        static void init_meta();
    };
}
