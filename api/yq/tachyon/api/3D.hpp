////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/N.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
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
    
        template <typename C>
        static void     init_meta(TachyonMeta::Writer<C>&);
    
    protected:

        ③();
        virtual ~③();
        
        void    snap(③Snap&) const;
        void    finalize(③Data&) const;
    };
}
