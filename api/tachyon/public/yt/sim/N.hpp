////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/keywords.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    struct ИData;
    struct ИSnap; 

    /*! \brief General N-dimensional object/presence 
    
        This is the root of an object that'll latch onto a spatial description.
    */
    class И {
    public:
    
        virtual uint8_t dimensions(count_k) const = 0;
        
        SpatialID       spatial() const { return m_spatial; }
        
    protected:
        И();
        virtual ~И();
        
        void            finalize(ИData&) const;
        void            snap(ИSnap&) const;
        void            mark();
        
        SpatialID       m_spatial;
    };
}
