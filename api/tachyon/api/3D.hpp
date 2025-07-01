////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/ID.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/N.hpp>
#include <tachyon/typedef/spatial3.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    struct ③Data;
    struct ③Snap;

#ifdef NAN
#undef NAN
#endif


    /*! \brief A base class for 3D objects that need spatial information
    
        \note We *CAN'T* derive from tachyon/delegate or we'll get that
        infamous diamond pattern.
    */
    class ③ : public И {
    public:

        virtual uint8_t dimensions(count_k) const override final { return 3; }

        struct SimpleParam {
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
        };
    

        //! Creates/sets a position (NOTE NOT THREAD SAFE!)
        //! Returns empty if one was not made (ie, we're not a tachyon)
        Spatial³ID    make_simple_spatial(
            const Vector3D& position,
            const Quaternion3D& orientation=IDENTITY,
            const Vector3D& scale=ONE
        );
    
        template <typename C>
        static void     init_info(TachyonMeta::Writer<C>&);
    
    protected:

        ③();
        virtual ~③();
        
        void    snap(③Snap&) const;
        void    finalize(③Data&) const;
    };
}
