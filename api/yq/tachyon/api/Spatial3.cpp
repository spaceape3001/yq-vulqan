////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Spatial3.hpp"
#include <yq/tachyon/api/Spatial3Data.hpp>
#include <yq/tachyon/api/Spatial3MetaWriter.hpp>
#include <yq/tachyon/api/Math.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial³);
YQ_TYPE_IMPLEMENT(yq::tachyon::Spatial³ID)

namespace yq::tachyon {
    Spatial³Meta::Spatial³Meta(std::string_view zName, SpatialMeta& base, const std::source_location& sl)
        : SpatialMeta(zName, base, sl)
    {
        set(Type::Spatial³);
    }

    Spatial³Meta::~Spatial³Meta()
    {
    }
    

    ////////////////////////////////////////////////////////////////////////////

    Spatial³::Spatial³() : Spatial³(Param())
    {
    }

    Spatial³::Spatial³(const Param& p) : Spatial(p)
    {
    }

    Spatial³::~Spatial³()
    {
    }

    void        Spatial³::snap(Spatial³Snap& sn) const
    {
        Spatial::snap(sn);
    }

    void        Spatial³::snap(Spatial³Snap&sn, const Vector3D& pos, const Tensor33D& T) const
    {
        snap(sn);
        calculate_transform_matrix(&sn.local2domain, &sn.domain2local, pos, T);
    }
    
    void        Spatial³::snap(Spatial³Snap&sn, const Vector3D& pos, const Tensor33D& T, const Vector3D& scale) const
    {
        snap(sn);
        calculate_transform_matrix(&sn.local2domain, &sn.domain2local, pos, T, scale);
    }

    void        Spatial³::snap(Spatial³Snap&sn, const Vector3D& pos, const Quaternion3D& ori) const
    {
        snap(sn);
        calculate_transform_matrix(&sn.local2domain, &sn.domain2local, pos, ori);
    }
    
    void        Spatial³::snap(Spatial³Snap&sn, const Vector3D& pos, const Quaternion3D& ori, const Vector3D& scale) const
    {
        snap(sn);
        calculate_transform_matrix(&sn.local2domain, &sn.domain2local, pos, ori, scale);
    }

    ////////////////////////////////////////////////////////////////////////////

    void Spatial³::init_meta()
    {
        auto w = writer<Spatial³>();
        w.description("Spatial in 3 Dimensions");
        w.abstract();
        w.alias("Spatial3");

        auto wt = writer<Spatial³ID>();
        wt.description("Spatial³ Identifier");
        wt.set(Meta::Flag::ID);
        wt.alias("Spatial3ID");
    }
}
