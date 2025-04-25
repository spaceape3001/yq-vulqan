////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size3.hpp>
#include <yq/vector/Vector3.hpp>
#include <yt/keywords.hpp>
#include <yt/api/Interface.hpp>

namespace yq::tachyon {
    class PMaxSize³;

    //! Interface for a single object max_size
    //! \note Inheritance is not permissible here
    class IMaxSize³ {
    public:
        YQ_INTERFACE_DECLARE(IMaxSize³, PMaxSize³)
        
        //!  Basic max_size in the 3I space
        virtual Size3D      max_size() const = 0;
        
        //!  Set max_size the max_size
        virtual void        max_size(set_k, const Size3D&){}
        virtual void        max_size(set_k, x_k, double){}
        virtual void        max_size(set_k, y_k, double){}
        virtual void        max_size(set_k, z_k, double){}
        
        //!  Move the max_size (ie set to max_size + delta)
        virtual void        max_size(add_k, const Vector3D&){}
        virtual void        max_size(add_k, x_k, double){}
        virtual void        max_size(add_k, y_k, double){}
        virtual void        max_size(add_k, z_k, double){}

        virtual void        max_size(multiply_k, double){}
        virtual void        max_size(multiply_k, const Vector3D&){}
        virtual void        max_size(multiply_k, x_k, double){}
        virtual void        max_size(multiply_k, y_k, double){}
        virtual void        max_size(multiply_k, z_k, double){}
        
        virtual bool        max_size(disabled_k) const { return false; }
        virtual bool        max_size(settable_k) const { return false; }
        virtual bool        max_size(addable_k) const { return false; }
        virtual bool        max_size(multipliable_k) const { return false; }

        static void init_info();
    };
}
