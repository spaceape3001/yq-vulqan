////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/ID.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/N.hpp>
//#include <tachyon/typedef/spatial.hpp>
//#include <tachyon/typedef/spatial2.hpp>
//#include <yq/typedef/tensor44.hpp>
//#include <yq/vector/Quaternion2.hpp>
//#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    struct ①Data;
    struct ①Snap;

#ifdef NAN
#undef NAN
#endif


    /*! \brief A base class for 2D objects that need spatial information
    
        \note We *CAN'T* derive from tachyon/delegate or we'll get that
        infamous diamond pattern.
    */
    class ① : public И {
    public:

        virtual uint8_t dimensions(count_k) const override final { return 1; }

#if 0
        struct SimpleParam {
            Vector1D        position        = NAN;
            Vector1D        scale           = NAN;
            bool            upward          = true; // facing upward (or downward)
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
        static void     init_info(TachyonMeta::Writer<C>&);
    
    protected:

        ①();
        virtual ~①();
        
        void    snap(①Snap&) const;
        void    finalize(①Data&) const;
    };
}
