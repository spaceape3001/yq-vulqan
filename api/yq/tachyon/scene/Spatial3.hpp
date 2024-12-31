////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/Spatial.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/typedef/tensor44.hpp>

namespace yq::tachyon {
    class Spatial3;
    
    class Spatial3Info : public SpatialInfo {
    public:
    
        template <typename C> class Writer;

        Spatial3Info(std::string_view zName, SpatialInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~Spatial3Info();
    
    };
    
    class Spatial3 : public Spatial {
        YQ_TACHYON_INFO(Spatial3Info)
        YQ_TACHYON_SNAP(Spatial3Snap)
        YQ_TACHYON_DATA(Spatial3Data)
        YQ_TACHYON_DECLARE(Spatial3, Spatial)
    public:
    
        virtual uint8_t dimensions(count_k) const override final { return 3; }
        
        Spatial3ID id() const { return Spatial3ID(UniqueID::id()); }

        static void init_info();
        
    protected:
        Spatial3(const Param&);
        virtual ~Spatial3();

        void        snap(Spatial3Snap&) const;
    };
}
