////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/scene/Scene.hpp>
#include <yt/scene/SceneData.hpp>
#include <yt/scene/SceneInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Scene);

namespace yq::tachyon {

    SceneInfo::SceneInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(name, base, sl)
    {
        set(Type::Scene);
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
    }
    
    void Scene::finalize(SceneData&data) const
    {
        Tachyon::finalize(data);
    }

    void Scene::init_info()
    {
        auto w = writer<Scene>();
        w.description("Scene");
    }

}


