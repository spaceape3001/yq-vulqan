////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scene3.hpp"
#include "Scene3Data.hpp"
#include "Scene3MetaWriter.hpp"

#include <yq/tachyon/api/dim/3DWriter.hxx>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Scene³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Scene³ID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Scene³Data)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Scene³Snap)

namespace yq::tachyon {

    Scene³Data::Scene³Data() = default;
    Scene³Data::~Scene³Data() = default;

    void Scene³Data::init_meta()
    {
        auto w = writer<Scene³Data>();
        w.description("Scene³ Frame Data");
    }


    /////////////////////////////////////////////////////////////////////////////

    Scene³Meta::Scene³Meta(std::string_view name, SceneMeta& base, const std::source_location& sl) :
        SceneMeta(name, base, sl)
    {
        set(Type::Scene³);
    }

    Scene³Meta::~Scene³Meta()
    {
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Scene³Snap::Scene³Snap() = default;
    Scene³Snap::~Scene³Snap() = default;

    void Scene³Snap::init_meta()
    {
        auto w = writer<Scene³Snap>();
        w.description("Scene³ Snapshot");
    }

    /////////////////////////////////////////////////////////////////////////////

    Scene³::Scene³(const Param& p) : Scene(p)
    {
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
    
    void Scene³::init_meta()
    {
        auto w = writer<Scene³>();
        ③::init_meta(w);
        w.description("Scene in 3D");
        w.alias("Scene3");

        auto wt = writer<Scene³ID>();
        wt.description("3D Scene Identifier");
        wt.set(Meta::Flag::ID);
        wt.alias("Scene3ID");
    }
}
