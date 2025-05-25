////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Spatial.hpp>
#include <tachyon/typedef/spatial2.hpp>

namespace yq::tachyon {
    class Spatial²;
    
    class Spatial²Info : public SpatialInfo {
    public:
    
        template <typename C> class Writer;

        Spatial²Info(std::string_view zName, SpatialInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~Spatial²Info();
    
    };
    
    class Spatial² : public Spatial {
        YQ_TACHYON_INFO(Spatial²Info)
        YQ_TACHYON_SNAP(Spatial²Snap)
        YQ_TACHYON_DATA(Spatial²Data)
        YQ_TACHYON_DECLARE(Spatial², Spatial)
    public:
    
        virtual uint8_t dimensions(count_k) const override final { return 3; }
        
        Spatial²ID id() const { return Spatial²ID(UniqueID::id()); }

        static void init_info();
        
    protected:
        Spatial²(const Param&);
        virtual ~Spatial²();

        void        snap(Spatial²Snap&) const;
    };
}

YQ_TYPE_DECLARE(yq::tachyon::Spatial²ID)
