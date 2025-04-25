////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>
#include <yt/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PMinSize²;

    //! Interface for a single object min_size
    //! \note Inheritance is not permissible here
    //! \note Standard for "NOT-SET" is NaN!
    class IMinSize² {
    public:
        YQ_INTERFACE_DECLARE(IMinSize², PMinSize²)
        
        //!  Basic min_size in the 2I space
        virtual Size2D      min_size() const = 0;
        
        //!  Set min_size the min_size
        virtual void        min_size(set_k, const Size2D&){}
        virtual void        min_size(set_k, x_k, double){}
        virtual void        min_size(set_k, y_k, double){}
        
        //!  Move the min_size (ie set to min_size + delta)
        virtual void        min_size(add_k, const Vector2D&){}
        virtual void        min_size(add_k, x_k, double){}
        virtual void        min_size(add_k, y_k, double){}

        virtual void        min_size(multiply_k, double){}
        virtual void        min_size(multiply_k, const Vector2D&){}
        virtual void        min_size(multiply_k, x_k, double){}
        virtual void        min_size(multiply_k, y_k, double){}
        
        virtual bool        min_size(disabled_k) const { return false; }
        virtual bool        min_size(settable_k) const { return false; }
        virtual bool        min_size(addable_k) const { return false; }
        virtual bool        min_size(multipliable_k) const { return false; }

        static void init_info();
    };
}

