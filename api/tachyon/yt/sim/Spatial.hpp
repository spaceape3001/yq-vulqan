////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Tachyon.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    class Spatial;
    
    class SpatialInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        SpatialInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~SpatialInfo();
    };


    /*! \brief Describer of x/y/z/etc in terms of relevant parametrics
    
        
    */
    class Spatial : public Tachyon {
        YQ_TACHYON_INFO(SpatialInfo)
        YQ_TACHYON_DATA(SpatialData)
        YQ_TACHYON_SNAP(SpatialSnap)
        YQ_TACHYON_DECLARE(Spatial, Tachyon)
    public:
    
        virtual uint8_t dimensions(count_k) const = 0;
    
        // For a geodetic based spatial, this domain would be the planet
        SpatialID       domain() const { return m_domain; }
        
        SpatialID       id() const { return SpatialID(UniqueID::id()); }

        static void init_info();
        
        struct Param : public Tachyon::Param {
            SpatialID   domain;
        };
    
    protected:
        Spatial(const Param&);
        virtual ~Spatial();
        
        void snap(SpatialSnap&) const;
    
    private:
        SpatialID       m_domain;
    };
}
YQ_TYPE_DECLARE(yq::tachyon::SpatialID)
