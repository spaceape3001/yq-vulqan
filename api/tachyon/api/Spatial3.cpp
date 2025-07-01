////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Spatial3.hpp>
#include <tachyon/api/Spatial3Data.hpp>
#include <tachyon/api/Spatial3InfoWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial³);
YQ_TYPE_IMPLEMENT(yq::tachyon::Spatial³ID)

namespace yq::tachyon {
    Spatial³Info::Spatial³Info(std::string_view zName, SpatialMeta& base, const std::source_location& sl)
        : SpatialMeta(zName, base, sl)
    {
        set(Type::Spatial³);
    }

    Spatial³Info::~Spatial³Info()
    {
    }
    

    ////////////////////////////////////////////////////////////////////////////

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

    ////////////////////////////////////////////////////////////////////////////

    void Spatial³::init_info()
    {
        auto w = writer<Spatial³>();
        w.description("Spatial in 3 Dimensions");
        w.abstract();

        auto wt = writer<Spatial³ID>();
        wt.description("Spatial³ Identifier");
        wt.set(Meta::Flag::ID);
    }
}
