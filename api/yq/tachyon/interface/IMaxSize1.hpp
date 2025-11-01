////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size1.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PMaxSize¹;

    //! Interface for a single object max_size
    //! \note Inheritance is not permissible here
    class IMaxSize¹ {
    public:
        YQ_INTERFACE_DECLARE(IMaxSize¹, PMaxSize¹)
        
        //!  Basic max_size in the 1I space
        virtual Size1D      max_size() const = 0;
        
        //!  Set max_size the max_size
        virtual void        max_size(set_k, const Size1D&){}
        virtual void        max_size(set_k, x_k, double){}
        
        //!  Move the max_size (ie set to max_size + delta)
        virtual void        max_size(add_k, const Vector1D&){}
        virtual void        max_size(add_k, x_k, double){}

        virtual void        max_size(multiply_k, double){}
        virtual void        max_size(multiply_k, const Vector1D&){}
        virtual void        max_size(multiply_k, x_k, double){}
        
        virtual bool        max_size(disabled_k) const { return false; }
        virtual bool        max_size(settable_k) const { return false; }
        virtual bool        max_size(addable_k) const { return false; }
        virtual bool        max_size(multipliable_k) const { return false; }

        static void init_meta();
    };
}

