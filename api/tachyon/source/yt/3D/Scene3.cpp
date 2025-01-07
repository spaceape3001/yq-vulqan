////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/3D/Scene3.hpp>
#include <yt/3D/Scene3Bind.hpp>
#include <yt/3D/Scene3Data.hpp>
#include <yt/3D/Scene3InfoWriter.hpp>
#include <ya/spatials/SimpleSpatial3.hpp>
#include <yt/3D/3DWriter.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Scene³)

namespace yq::tachyon {
    /////////////////////////////////////////////////////////////////////////////

    Scene³Bind::Scene³Bind(const Scene³* v) : m_scene³(v?v->id():Scene³ID()) 
    {
    }
    
    Scene³Bind::Scene³Bind(TypedID v) : m_scene³(v(Type::Scene³) ? Scene³ID(v.id) : Scene³ID())
    {
    }

    /////////////////////////////////////////////////////////////////////////////

    Scene³Data::Scene³Data() = default;
    Scene³Data::~Scene³Data() = default;

    /////////////////////////////////////////////////////////////////////////////

    Scene³Info::Scene³Info(std::string_view name, SceneInfo& base, const std::source_location& sl) :
        SceneInfo(name, base, sl)
    {
    }

    Scene³Info::~Scene³Info()
    {
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Scene³Snap::Scene³Snap() = default;
    Scene³Snap::~Scene³Snap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Scene³::Scene³(const Param& p) : Scene(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            make_simple_spatial(p.position, p.orientation, p.scale);
        }
    }
    
    Scene³::~Scene³()
    {
    }
    
    void Scene³::finalize(Scene³Data& d) const
    {
        ③::finalize(d);
        Scene::finalize(d);
    }

    void Scene³::snap(Scene³Snap& sn) const
    {
        ③::snap(sn);
        Scene::snap(sn);
    }
    
    void Scene³::init_info()
    {
        auto w = writer<Scene³>();
        ③::init_info(w);
        w.description("Scene in 3D");
    }
}
