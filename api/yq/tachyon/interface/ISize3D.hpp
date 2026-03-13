////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/typedef/size3.hpp>
#include <yq/typedef/vector3.hpp>

namespace yq::tachyon {
    class PSize³D;

    //! Interface for a single object size
    //! \note Inheritance is not permissible here
    class ISize³D {
    public:
        YQ_INTERFACE_DECLARE(ISize³D, PSize³D)
        
        //!  Basic size in the 3I space
        virtual Size3D      size() const = 0;
        
        //!  Set size the size
        virtual void        size(set_k, const Size3D&){}
        virtual void        size(set_k, x_k, double){}
        virtual void        size(set_k, y_k, double){}
        virtual void        size(set_k, z_k, double){}
        
        //!  Move the size (ie set to size + delta)
        virtual void        size(add_k, const Size3D&){}
        void                size(add_k, const Vector3D&);
        virtual void        size(add_k, x_k, double){}
        virtual void        size(add_k, y_k, double){}
        virtual void        size(add_k, z_k, double){}

        virtual void        size(multiply_k, double){}
        virtual void        size(multiply_k, const Vector3D&){}
        virtual void        size(multiply_k, x_k, double){}
        virtual void        size(multiply_k, y_k, double){}
        virtual void        size(multiply_k, z_k, double){}
        
        virtual bool        size(disabled_k) const { return false; }
        virtual bool        size(settable_k) const { return false; }
        virtual bool        size(addable_k) const { return false; }
        virtual bool        size(multipliable_k) const { return false; }

        static void init_meta();
    };
}
