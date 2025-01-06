////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/keywords.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    struct ИData;
    struct ИSnap;
    class Tachyon; 

    /*! \brief General N-dimensional object/presence 
    
        This is the root of an object that'll latch onto a spatial description.
    */
    class И {
    public:
    
        virtual uint8_t dimensions(count_k) const = 0;
        
        SpatialID       spatial() const { return m_spatial; }
        
        //  \brief Sets the spatial 
        //  \note Not thread safe
        void            set_spatial(SpatialID);

        template <typename C>
        static void     init_info(TachyonInfo::Writer<C>&);

    protected:
        И();
        virtual ~И();
        
        void            finalize(ИData&) const;
        void            snap(ИSnap&) const;
        void            mark();
        TachyonID       tachyon_id() const;
        
        
        SpatialID       m_spatial;
    };
}
