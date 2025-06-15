////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Spatial2.hpp>
#include <tachyon/api/Spatial2Data.hpp>
#include <tachyon/api/Spatial2InfoWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial²);
YQ_TYPE_IMPLEMENT(yq::tachyon::Spatial²ID)

namespace yq::tachyon {
    Spatial²Info::Spatial²Info(std::string_view zName, SpatialInfo& base, const std::source_location& sl)
        : SpatialInfo(zName, base, sl)
    {
        set(Type::Spatial²);
    }

    Spatial²Info::~Spatial²Info()
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

    void Spatial²::init_info()
    {
        auto w = writer<Spatial²>();
        w.description("Spatial in 2 Dimensions");
        w.abstract();

        auto wt = writer<Spatial²ID>();
        wt.description("Spatial² Identifier");
        wt.set(Meta::Flag::ID);
    }
}
