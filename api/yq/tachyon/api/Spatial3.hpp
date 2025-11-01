////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Spatial.hpp>
#include <tachyon/typedef/spatial3.hpp>
#include <yq/typedef/tensor44.hpp>

namespace yq::tachyon {
    class Spatial³;
    
    class Spatial³Meta : public SpatialMeta {
    public:
    
        template <typename C> class Writer;

        Spatial³Meta(std::string_view zName, SpatialMeta& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~Spatial³Meta();
    
    };
    
    class Spatial³ : public Spatial {
        YQ_TACHYON_META(Spatial³Meta)
        YQ_TACHYON_SNAP(Spatial³Snap)
        YQ_TACHYON_DATA(Spatial³Data)
        YQ_TACHYON_DECLARE(Spatial³, Spatial)
    public:
    
        virtual uint8_t dimensions(count_k) const override final { return 3; }
        
        Spatial³ID id() const { return Spatial³ID(UniqueID::id()); }

        static void init_meta();
        
    protected:
        Spatial³(const Param&);
        virtual ~Spatial³();

        void        snap(Spatial³Snap&) const;
    };
}

YQ_TYPE_DECLARE(yq::tachyon::Spatial³ID)
