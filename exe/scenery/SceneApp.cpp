////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneApp.hpp"
#include "SceneEditor.hpp"
#include <yq/assetvk/camera/SpaceCamera.hpp>
#include <yq/assetvk/scene/SimpleScene.hpp>
#include <yq/assetvk/spatial/SimpleSpatial3.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

SceneApp* SceneApp::s_app = nullptr;

SceneApp::SceneApp(int argc, char* argv[], const AppCreateInfo& aci) : Application(argc, argv, aci)
{
    s_app   = this;

    for(int n=1;n<argc;++n){
        if(argv[n][0] == '-'){
            std::string_view    rem(argv[n]+2);
            switch(argv[n][1]){
            case 'R':
                m_respath.push_back(rem);
                break;
            case 'P':
                m_plugins.push_back(rem);
                break;
            }
        } else
            m_imports.push_back(argv[n]);
    }
            
}

SceneApp::~SceneApp()
{
    s_app = nullptr;
}

bool   SceneApp::startup(SceneEditor& you)
{
    lock_t  _lock;
    if(!_lock.try_acquire(m_mutex, true))
        return false;
        
    if(!m_defScene){
        Scene*  scene   = Tachyon::create_on<SimpleScene>(AUX);
        scene->set_name("SceneEditor Default Scene");
        m_defScene  = *scene;
        return false;
    }
    
    const Frame*    frame   = Frame::current();
    if(!frame)
        return false;
    if(!frame->contains(m_defScene))
        return false;
    
    m_viewers.insert(you.viewer());
    return true;
}


bool        SceneApp::teardown(ViewerID vid)
{
    lock_t  _lock(m_mutex, true);
    m_viewers.erase(vid);
    return m_viewers.empty();
}
