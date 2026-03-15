////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Spatial2.hpp>
#include <yq/tachyon/api/Spatial2Data.hpp>
#include <yq/tachyon/api/Spatial2MetaWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial²);
YQ_TYPE_IMPLEMENT(yq::tachyon::Spatial²ID)

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
