////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Kinetic3.hpp"
#include "Kinetic3Data.hpp"
#include "Kinetic3MetaWriter.hpp"
#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tachyon/api/dim/3DWriter.hxx>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Kinetic³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Kinetic³ID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Kinetic³Data)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Kinetic³Snap)

namespace yq::tachyon {
    Kinetic³Meta::Kinetic³Meta(std::string_view name, KineticMeta& base, const std::source_location& sl) :
        KineticMeta(name, base, sl)
    {
        set(Type::Kinetic³);
    }

    Kinetic³Meta::~Kinetic³Meta()
    {
    }

    ////////////////////////////////////

    Kinetic³Data::Kinetic³Data() = default;
    Kinetic³Data::~Kinetic³Data() = default;

    void Kinetic³Data::init_meta()
    {
        auto w = writer<Kinetic³Data>();
        w.description("Kinetic³ Frame Data");
    }

    ////////////////////////////////////

    Kinetic³Snap::Kinetic³Snap() = default;
    Kinetic³Snap::~Kinetic³Snap() = default;

    void Kinetic³Snap::init_meta()
    {
        auto w = writer<Kinetic³Snap>();
        w.description("Kinetic³ Snapshot");
    }
        
    ////////////////////////////////////

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
