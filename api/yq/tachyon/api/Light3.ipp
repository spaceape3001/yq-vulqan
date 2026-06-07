////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Light3.hpp"
#include "Light3Data.hpp"
#include "Light3MetaWriter.hpp"
#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tachyon/api/dim/3DWriter.hxx>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Light³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Light³ID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Light³Data)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Light³Snap)

namespace yq::tachyon {
    Light³Meta::Light³Meta(std::string_view name, LightMeta& base, const std::source_location& sl) :
        LightMeta(name, base, sl)
    {
        set(Type::Light³);
    }

    Light³Meta::~Light³Meta()
    {
    }
    
    ////////////////////////////

    Light³Data::Light³Data() = default;
    Light³Data::~Light³Data() = default;
    
    void Light³Data::init_meta()
    {
        auto w = writer<Light³Data>();
        w.description("Light Frame Data");
    }

    ////////////////////////////

    Light³Snap::Light³Snap() = default;
    Light³Snap::~Light³Snap() = default;
    
    void Light³Snap::init_meta()
    {
        auto w = writer<Light³Snap>();
        w.description("Light Snapshot");
    }
    
    ///////////////////////
    
    Light³::Light³(const Param& p) : Light(p)
    {
    }
    
    Light³::~Light³()
    {
    }
    
    
    void Light³::finalize(Light³Data&d) const
    {
        ③::finalize(d);
        Light::finalize(d);
    }

    void Light³::snap(Light³Snap& sn) const
    {
        ③::snap(sn);
        Light::snap(sn);
    }
    
    void Light³::init_meta()
    {
        auto w = writer<Light³>();
        ③::init_meta(w);
        w.description("Light in 3D");
        w.alias("Light3");
        w.abstract();

        auto wt = writer<Light³ID>();
        wt.description("3D Light Identifier");
        wt.set(Meta::Flag::ID);
        wt.alias("Light3ID");
    }
}
