////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size4.hpp>
#include <yq/vector/Vector4.hpp>
#include <yt/keywords.hpp>
#include <yt/api/Interface.hpp>

namespace yq::tachyon {
    class PMaxSize⁴;

    //! Interface for a single object max_size
    //! \note Inheritance is not permissible here
    class IMaxSize⁴ {
    public:
        YQ_INTERFACE_DECLARE(IMaxSize⁴, PMaxSize⁴)
        
        //!  Basic max_size in the 4I space
        virtual Size4D      max_size() const = 0;
        
        //!  Set max_size the max_size
        virtual void        max_size(set_k, const Size4D&){}
        virtual void        max_size(set_k, x_k, double){}
        virtual void        max_size(set_k, y_k, double){}
        virtual void        max_size(set_k, z_k, double){}
        virtual void        max_size(set_k, w_k, double){}
        
        //!  Move the max_size (ie set to max_size + delta)
        virtual void        max_size(add_k, const Vector4D&){}
        virtual void        max_size(add_k, x_k, double){}
        virtual void        max_size(add_k, y_k, double){}
        virtual void        max_size(add_k, z_k, double){}
        virtual void        max_size(add_k, w_k, double){}

        virtual void        max_size(multiply_k, double){}
        virtual void        max_size(multiply_k, const Vector4D&){}
        virtual void        max_size(multiply_k, x_k, double){}
        virtual void        max_size(multiply_k, y_k, double){}
        virtual void        max_size(multiply_k, z_k, double){}
        virtual void        max_size(multiply_k, w_k, double){}
        
        virtual bool        max_size(disabled_k) const { return false; }
        virtual bool        max_size(settable_k) const { return false; }
        virtual bool        max_size(addable_k) const { return false; }
        virtual bool        max_size(multipliable_k) const { return false; }

        static void init_info();
    };
}
