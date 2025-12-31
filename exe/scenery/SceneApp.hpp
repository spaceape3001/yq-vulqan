////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Execution.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/controller.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <tbb/spin_rw_mutex.h>

using namespace yq;
using namespace yq::tachyon;

class SceneEditor;

class SceneApp : public Application {
public:
    SceneApp(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
    ~SceneApp();
    
    static SceneApp*  app() { return s_app; }
    
    auto& imports() const { return m_imports; }
    auto& plugins() const { return m_plugins; }
    auto& vlibs() const { return m_vlibs; }
    auto& respath() const { return m_respath; }
    
    //! Returns TRUE if this is the final "teardown" of this viewer
    bool        teardown(ViewerID);

    bool        startup(SceneEditor& you);
    
    TypedID     default_scene() const { return m_defScene; }
    
private:
    static SceneApp*    s_app;

    using mutex_t = tbb::spin_rw_mutex;
    using lock_t = mutex_t::scoped_lock;

    std::vector<std::filesystem::path>  m_imports, m_plugins, m_vlibs, m_respath;
    std::set<ViewerID>          m_viewers;
    TypedID                     m_defScene;
    mutable mutex_t                 m_mutex;
};
