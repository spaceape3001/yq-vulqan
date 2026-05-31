////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Kinetic3.hpp"
#include "Kinetic3Data.hpp"
#include "Kinetic3MetaWriter.hpp"
#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tachyon/api/3DWriter.hxx>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Kinetic³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Kinetic³ID)

namespace yq::tachyon {
    Kinetic³Meta::Kinetic³Meta(std::string_view name, KineticMeta& base, const std::source_location& sl) :
        KineticMeta(name, base, sl)
    {
        set(Type::Kinetic³);
    }

    Kinetic³Meta::~Kinetic³Meta()
    {
    }
    

    Kinetic³::Kinetic³(const Param& p) : Kinetic(p)
    {
    }
    
    Kinetic³::~Kinetic³()
    {
    }
    
    
    void Kinetic³::finalize(Kinetic³Data&d) const
    {
        ③::finalize(d);
        Kinetic::finalize(d);
    }

    void Kinetic³::snap(Kinetic³Snap& sn) const
    {
        ③::snap(sn);
        Kinetic::snap(sn);
    }
    
    void Kinetic³::init_meta()
    {
        auto w = writer<Kinetic³>();
        ③::init_meta(w);
        w.description("Kinetic in 3D");
        w.alias("Kinetic3");
        w.abstract();

        auto wt = writer<Kinetic³ID>();
        wt.description("3D Kinetic Identifier");
        wt.set(Meta::Flag::ID);
        wt.alias("Kinetic3ID");
    }
}
