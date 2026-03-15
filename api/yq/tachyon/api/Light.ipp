////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/api/LightMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/command/light/LightColorCommand.hpp>
#include <yq/tachyon/command/light/LightIntensityCommand.hpp>
#include <yq/tachyon/event/light/LightColorEvent.hpp>
#include <yq/tachyon/event/light/LightIntensityEvent.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct LightMeta::Repo {
        std::vector<const LightMeta*> all;
    };
    
    LightMeta::Repo& LightMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const LightMeta*>&    LightMeta::all()
    {
        return repo().all;
    }

    LightMeta::LightMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
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

    void Light::on_light_color_command(const LightColorCommand&cmd)
    {
        if(cmd.target().id != id())
            return;
        m_color     = cmd.color();
        mark();
        send(new LightColorEvent({}, m_color));
    }
    
    void Light::on_light_intensity_command(const LightIntensityCommand&cmd)
    {
        if(cmd.target().id != id())
            return;
        m_intensity = cmd.intensity();
        mark();
        send(new LightIntensityEvent({}, m_intensity));
    }

    void Light::snap(LightSnap& sn) const
    {
        Tachyon::snap(sn);
        sn.color        = m_color;
        sn.intensity    = m_intensity;
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Light::init_meta()
    {
        auto w   = writer<Light>();
        w.abstract();
        w.description("Light, illumination");
        w.slot(&Light::on_light_color_command);
        w.slot(&Light::on_light_intensity_command);

        auto wt = writer<LightID>();
        wt.description("Light Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Light>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Light)
YQ_TYPE_IMPLEMENT(yq::tachyon::LightID)
