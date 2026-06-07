////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Spatial2.hpp"
#include "Spatial2Data.hpp"
#include "Spatial2MetaWriter.hpp"
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial²);
YQ_TYPE_IMPLEMENT(yq::tachyon::Spatial²ID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Spatial²Data)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Spatial²Snap)

namespace yq::tachyon {
    Spatial²Meta::Spatial²Meta(std::string_view zName, SpatialMeta& base, const std::source_location& sl)
        : SpatialMeta(zName, base, sl)
    {
        set(Type::Spatial²);
    }

    Spatial²Meta::~Spatial²Meta()
    {
    }
    

    ////////////////////////////////////////////////////////////////////////////

    Spatial²Data::Spatial²Data() = default;
    Spatial²Data::~Spatial²Data() = default;
    
    void Spatial²Data::init_meta()
    {
        auto w = writer<Spatial²Data>();
        w.description("Spatial² Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////

    Spatial²Snap::Spatial²Snap() = default;
    Spatial²Snap::~Spatial²Snap() = default;
    
    void Spatial²Snap::init_meta()
    {
        auto w = writer<Spatial²Snap>();
        w.description("Spatial² Snapshot");
    }
    
    ////////////////////////////////////////////////////////////////////////////

    Spatial²::Spatial²(const Param& p) : Spatial(p)
    {
    }
    
    Spatial²::~Spatial²()
    {
    }

    void        Spatial²::snap(Spatial²Snap& sn) const
    {
        Spatial::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////

    void Spatial²::init_meta()
    {
        auto w = writer<Spatial²>();
        w.description("Spatial in 2 Dimensions");
        w.abstract();
        w.alias("Spatial2");

        auto wt = writer<Spatial²ID>();
        wt.description("Spatial² Identifier");
        wt.set(Meta::Flag::ID);
        wt.alias("Spatial2ID");
    }
}
