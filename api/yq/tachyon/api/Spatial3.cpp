////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Spatial3Data.hpp>
#include <yq/tachyon/api/Spatial3MetaWriter.hpp>
#include <yq/tensor/Tensor33.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/meta/Init.hpp>

#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

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

    void        Spatial³::snap(Spatial³Snap&sn, const Vector3D& pos, const Quaternion3D& ori) const
    {
        Spatial::snap(sn);

        Tensor33D   T    = tensor(ori);
        Tensor33D   T2   = inverse(T);
        Vector3D    pos2 = T2 * pos;
        
        sn.local2domain = Tensor44D(
            T.xx, T.xy, T.xz, pos.x,
            T.yx, T.yy, T.yz, pos.y,
            T.zx, T.zy, T.zz, pos.z,
            0., 0., 0., 1.
        );
        
        sn.domain2local = Tensor44D(
            T2.xx, T2.xy, T2.xz, -pos2.x,
            T2.yx, T2.yy, T2.yz, -pos2.y,
            T2.zx, T2.zy, T2.zz, -pos2.z,
            0., 0., 0., 1.
        );
    }
    
    void        Spatial³::snap(Spatial³Snap&sn, const Vector3D& pos, const Quaternion3D& ori, const Vector3D& scale) const
    {
        Spatial::snap(sn);

        Tensor33D   T    = tensor(ori) * diagonal(scale);
        Tensor33D   T2   = inverse(T);
        Vector3D    pos2 = T2 * pos;
        
        sn.local2domain = Tensor44D(
            T.xx, T.xy, T.xz, pos.x,
            T.yx, T.yy, T.yz, pos.y,
            T.zx, T.zy, T.zz, pos.z,
            0., 0., 0., 1.
        );
        
        sn.domain2local = Tensor44D(
            T2.xx, T2.xy, T2.xz, -pos2.x,
            T2.yx, T2.yy, T2.yz, -pos2.y,
            T2.zx, T2.zy, T2.zz, -pos2.z,
            0., 0., 0., 1.
        );
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
