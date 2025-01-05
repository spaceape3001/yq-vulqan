////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/sim/N.hpp>
#include <yt/typedef/spatial3.hpp>
#include <yq/typedef/tensor44.hpp>

namespace yq::tachyon {

    struct ③Data;
    struct ③Snap;


    /*! \brief A base class for 3D objects that need spatial information
    
        \note We *CAN'T* derive from tachyon/delegate or we'll get that
        infamous diamond pattern.
    */
    class ③ : public И {
    public:

        virtual uint8_t dimensions(count_k) const override final { return 3; }
    
    protected:

        //! Gets the matrics from the spatials
        Tensor44D   local2domain() const;

        //! Gets the matrics from the spatials
        Tensor44D   domain2local() const;
    
    
        ③();
        virtual ~③();
        
        void    snap(③Snap&) const;
        void    finalize(③Data&) const;
    };
}
