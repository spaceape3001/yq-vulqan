////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/3D/Scene3.hpp>
#include <yq/tachyon/3D/Scene3Bind.hpp>
#include <yq/tachyon/3D/Scene3Data.hpp>
#include <yq/tachyon/3D/Scene3InfoWriter.hpp>
#include <ya/spatials/SimpleSpatial3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Scene³)

namespace yq::tachyon {
    Scene³Info::Scene³Info(std::string_view name, SceneInfo& base, const std::source_location& sl) :
        SceneInfo(name, base, sl)
    {
    }

    Scene³Info::~Scene³Info()
    {
    }
    

    Scene³::Scene³(const Param& p) : Scene(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            SimpleSpatial³::Param p3;
            p3.position     = p.position;
            p3.orientation  = p.orientation;
            p3.scale        = p.scale;
            m_spatial       = create<SimpleSpatial³>(CHILD, p3) -> id();
            subscribe(m_spatial, MG::Spatial);
        }
    }
    
    Scene³::~Scene³()
    {
    }
    
    void Scene³::snap(Scene³Snap& sn) const
    {
        Scene::snap(sn);
    }
    
    void Scene³::init_info()
    {
        auto w = writer<Scene³>();
        w.description("Scene in 3D");
    }
}
