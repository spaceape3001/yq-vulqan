////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/scene/Light.hpp>
#include <yt/scene/LightData.hpp>
#include <yt/scene/LightInfoWriter.hpp>
#include <yt/msg/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct LightInfo::Repo {
        std::vector<const LightInfo*> all;
    };
    
    LightInfo::Repo& LightInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const LightInfo*>&    LightInfo::all()
    {
        return repo().all;
    }

    LightInfo::LightInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Light);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Light::Light(const Param& p) : Tachyon(p)
    {
    }

    Light::~Light()
    {
    }

    void Light::finalize(LightData&d) const
    {
        Tachyon::finalize(d);
    }

    void Light::snap(LightSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Light::init_info()
    {
        auto w   = writer<Light>();
        w.abstract();
        w.description("Light, illumination");

        auto wt = writer<LightID>();
        wt.description("Light Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Light)
YQ_TYPE_IMPLEMENT(yq::tachyon::LightID)
