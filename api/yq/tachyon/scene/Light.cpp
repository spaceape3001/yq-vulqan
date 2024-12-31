////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/scene/Light.hpp>
#include <yq/tachyon/scene/LightBind.hpp>
#include <yq/tachyon/scene/LightData.hpp>
#include <yq/tachyon/scene/LightInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    LightBind::LightBind(const Light* v) : m_light(v ? v->id() : LightID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    PostAdvice    Light::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const LightBind* p = dynamic_cast<const LightBind*>(&pp)){
            if(p->light() != id())
                return REJECT;
        }
        return {};
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
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Light)
