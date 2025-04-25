////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>
#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PMaxSize²;

    //! Interface for a single object max_size
    //! \note Inheritance is not permissible here
    class IMaxSize² {
    public:
        YQ_INTERFACE_DECLARE(IMaxSize², PMaxSize²)
        
        //!  Basic max_size in the 2I space
        virtual Size2D      max_size() const = 0;
        
        //!  Set max_size the max_size
        virtual void        max_size(set_k, const Size2D&){}
        virtual void        max_size(set_k, x_k, double){}
        virtual void        max_size(set_k, y_k, double){}
        
        //!  Move the max_size (ie set to max_size + delta)
        virtual void        max_size(add_k, const Vector2D&){}
        virtual void        max_size(add_k, x_k, double){}
        virtual void        max_size(add_k, y_k, double){}

        virtual void        max_size(multiply_k, double){}
        virtual void        max_size(multiply_k, const Vector2D&){}
        virtual void        max_size(multiply_k, x_k, double){}
        virtual void        max_size(multiply_k, y_k, double){}
        
        virtual bool        max_size(disabled_k) const { return false; }
        virtual bool        max_size(settable_k) const { return false; }
        virtual bool        max_size(addable_k) const { return false; }
        virtual bool        max_size(multipliable_k) const { return false; }

        static void init_info();
    };
}

