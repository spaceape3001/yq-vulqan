////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/N.hpp>
//#include <yq/tachyon/typedef/spatial.hpp>
//#include <yq/tachyon/typedef/spatial2.hpp>
//#include <yq/typedef/tensor44.hpp>
//#include <yq/vector/Quaternion2.hpp>
//#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    struct ②Data;
    struct ②Snap;

#ifdef NAN
#undef NAN
#endif


    /*! \brief A base class for 2D objects that need spatial information
    
        \note We *CAN'T* derive from tachyon/delegate or we'll get that
        infamous diamond pattern.
    */
    class ② : public И {
    public:

        virtual uint8_t dimensions(count_k) const override final { return 2; }

#if 0
        struct SimpleParam {
            Vector2D        position        = NAN;
            Quaternion2D    orientation     = NAN;
            Vector2D        scale           = NAN;
        };
    

        //! Creates/sets a position (NOTE NOT THREAD SAFE!)
        //! Returns empty if one was not made (ie, we're not a tachyon)
        Spatial³ID    make_simple_spatial(
            const Vector2D& position,
            const Quaternion2D& orientation=IDENTITY,
            const Vector2D& scale=ONE
        );
#endif
    
        template <typename C>
        static void     init_meta(TachyonMeta::Writer<C>&);
    
    protected:

        ②();
        virtual ~②();
        
        void    snap(②Snap&) const;
        void    finalize(②Data&) const;
    };
}
