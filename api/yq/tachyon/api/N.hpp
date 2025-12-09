////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    struct ИData;
    struct ИSnap;
    class Tachyon; 
    class SpatialCommand;
    class SpatialEvent;
    class SetSpatialCommand;

    /*! \brief General N-dimensional object/presence 
    
        This is the root of an object that'll latch onto a spatial description.
    */
    class И : public virtual Tachyon::Helper {
    public:
    
        virtual uint8_t dimensions(count_k) const = 0;
        
        TypedID         spatial() const { return m_spatial; }
        
        //  \brief Sets the spatial 
        //  \note Not thread safe
        void            set_spatial(TypedID);

        void            set_spatial(SpatialID);

        template <typename C>
        static void     init_meta(TachyonMeta::Writer<C>&);
        
        //! Creates a "child" spatial and sets it as our spatial
        template <SomeSpatial T, typename ... Args>
        T*          create_spatial(Args&&...);

        //! Creates a "child" spatial and sets it as our spatial
        template <SomeSpatial T=Spatial>
        T*          create_spatial(const typename T::MyMeta&);        

    protected:
        И();
        virtual ~И();
        
        void            finalize(ИData&) const;
        void            snap(ИSnap&) const;
        
        TachyonID       tachyon_id() const;
        
        void            on_spatial_command(const SpatialCommand&);
        void            on_spatial_event(const SpatialEvent&);
        void            on_set_spatial_command(const SetSpatialCommand&);
        
        TypedID        m_spatial;
    };
}
