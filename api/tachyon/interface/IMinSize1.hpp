////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size1.hpp>
#include <yq/vector/Vector1.hpp>
#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PMinSize¹;

    //! Interface for a single object min_size
    //! \note Inheritance is not permissible here
    class IMinSize¹ {
    public:
        YQ_INTERFACE_DECLARE(IMinSize¹, PMinSize¹)
        
        //!  Basic min_size in the 1I space
        virtual Size1D      min_size() const = 0;
        
        //!  Set min_size the min_size
        virtual void        min_size(set_k, const Size1D&){}
        virtual void        min_size(set_k, x_k, double){}
        
        //!  Move the min_size (ie set to min_size + delta)
        virtual void        min_size(add_k, const Vector1D&){}
        virtual void        min_size(add_k, x_k, double){}

        virtual void        min_size(multiply_k, double){}
        virtual void        min_size(multiply_k, const Vector1D&){}
        virtual void        min_size(multiply_k, x_k, double){}
        
        virtual bool        min_size(disabled_k) const { return false; }
        virtual bool        min_size(settable_k) const { return false; }
        virtual bool        min_size(addable_k) const { return false; }
        virtual bool        min_size(multipliable_k) const { return false; }

        static void init_meta();
    };
}

