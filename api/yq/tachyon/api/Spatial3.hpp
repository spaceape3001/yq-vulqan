////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/typedef/quaternion3.hpp>
#include <yq/typedef/tensor33.hpp>
#include <yq/typedef/tensor44.hpp>
#include <yq/typedef/vector3.hpp>

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
        Spatial³();
        Spatial³(const Param&);
        virtual ~Spatial³();

        void        snap(Spatial³Snap&) const;
        void        snap(Spatial³Snap&, const Vector3D& pos, const Quaternion3D& ori) const;
        void        snap(Spatial³Snap&, const Vector3D& pos, const Quaternion3D& ori, const Vector3D& scale) const;
        void        snap(Spatial³Snap&, const Vector3D& pos, const Tensor33D& ori) const;
        void        snap(Spatial³Snap&, const Vector3D& pos, const Tensor33D& ori, const Vector3D& scale) const;
    };
}

YQ_TYPE_DECLARE(yq::tachyon::Spatial³ID)
