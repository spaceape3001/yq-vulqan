////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size3.hpp>
#include <yq/vector/Vector3.hpp>
#include <yt/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PSize³;

    //! Interface for a single object size
    //! \note Inheritance is not permissible here
    class ISize³ {
    public:
        YQ_INTERFACE_DECLARE(ISize³, PSize³)
        
        //!  Basic size in the 3I space
        virtual Size3D      size() const = 0;
        
        //!  Set size the size
        virtual void        size(set_k, const Size3D&){}
        virtual void        size(set_k, x_k, double){}
        virtual void        size(set_k, y_k, double){}
        virtual void        size(set_k, z_k, double){}
        
        //!  Move the size (ie set to size + delta)
        virtual void        size(add_k, const Vector3D&){}
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

        static void init_info();
    };
}
