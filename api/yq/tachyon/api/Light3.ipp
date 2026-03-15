////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Light3Data.hpp>
#include <yq/tachyon/api/Light3MetaWriter.hpp>
#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tachyon/api/3DWriter.hxx>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Light³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Light³ID)

namespace yq::tachyon {
    Light³Meta::Light³Meta(std::string_view name, LightMeta& base, const std::source_location& sl) :
        LightMeta(name, base, sl)
    {
        set(Type::Light³);
    }

    Light³Meta::~Light³Meta()
    {
    }
    

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
