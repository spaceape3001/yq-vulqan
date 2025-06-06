////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/tags.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/api/SceneInfoWriter.hpp>
#include <tachyon/command/color/SetBgColorCommand.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Scene);
YQ_TYPE_IMPLEMENT(yq::tachyon::SceneID)

namespace yq::tachyon {

    struct SceneInfo::Repo {
        std::vector<const SceneInfo*> all;
    };
    
    SceneInfo::Repo& SceneInfo::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    const std::vector<const SceneInfo*>&    SceneInfo::all()
    {
        return repo().all;
    }

    SceneInfo::SceneInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(name, base, sl)
    {
        set(Type::Scene);
        repo().all.push_back(this);
    }
    
    SceneInfo::~SceneInfo()
    {
    }
    

    Scene::Scene(const Param&p) : Tachyon(p)
    {
    }
    
    Scene::~Scene()
    {
    }

    void Scene::snap(SceneSnap&sn) const
    {
        Tachyon::snap(sn);
        sn.bgcolor  = m_bgcolor;
    }
    
    void Scene::finalize(SceneData&data) const
    {
        Tachyon::finalize(data);
    }

    void Scene::on_set_bg_color(const SetBgColorCommand&cmd)
    {
        if(cmd.target() == id()){
            m_bgcolor = cmd.bgcolor();
            mark();
        }
    }

    void Scene::set_bgcolor(const RGBA4F&v)
    {
        m_bgcolor = v;
        mark();
    }

    void Scene::init_info()
    {
        auto w = writer<Scene>();
        w.description("Scene");
        w.property("bgcolor", &Scene::bgcolor).setter(&Scene::set_bgcolor).tag(kTag_Save);
        w.slot(&Scene::on_set_bg_color);

        auto wt = writer<SceneID>();
        wt.description("Scene Identifier");
        wt.set(Meta::Flag::ID);
    }

}


