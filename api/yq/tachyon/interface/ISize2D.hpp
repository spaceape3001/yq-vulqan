////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/vector2.hpp>

namespace yq::tachyon {
    class PSize²D;

    //! Interface for a single object size
    //! \note Inheritance is not permissible here
    class ISize²D {
    public:
        YQ_INTERFACE_DECLARE(ISize²D, PSize²D)
        
        //!  Basic size in the 2I space
        virtual Size2D      size() const = 0;
        
        //!  Set size the size
        virtual void        size(set_k, const Size2D&){}
        virtual void        size(set_k, x_k, double){}
        virtual void        size(set_k, y_k, double){}
        
        //!  Move the size (ie set to size + delta)
        virtual void        size(add_k, const Size2D&){}
        void                size(add_k, const Vector2D&);
        virtual void        size(add_k, x_k, double){}
        virtual void        size(add_k, y_k, double){}

        virtual void        size(multiply_k, double){}
        virtual void        size(multiply_k, const Vector2D&){}
        virtual void        size(multiply_k, x_k, double){}
        virtual void        size(multiply_k, y_k, double){}
        
        virtual bool        size(disabled_k) const { return false; }
        virtual bool        size(settable_k) const { return false; }
        virtual bool        size(addable_k) const { return false; }
        virtual bool        size(multipliable_k) const { return false; }

        static void init_meta();
    };
}

