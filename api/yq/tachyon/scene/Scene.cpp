////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/scene/Scene.hpp>
#include <yq/tachyon/scene/SceneBind.hpp>
#include <yq/tachyon/scene/SceneData.hpp>
#include <yq/tachyon/scene/SceneInfoWriter.hpp>

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
    
    void Scene::init_info()
    {
        auto w = writer<Scene>();
        w.description("Scene");
    }

}


