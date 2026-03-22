////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "YApp.hpp"
#include "YAppThread.hpp"

//#include "../XObject.hpp"
//#include "../XTachyon.hpp"
//#include "../XWidget.hpp"

#include <yq/tachyon/thread/AudioThread.hpp>
#include <yq/tachyon/thread/AuxillaryThread.hpp>
#include <yq/tachyon/thread/EditThread.hpp>
#include <yq/tachyon/thread/GameThread.hpp>
#include <yq/tachyon/thread/IOThread.hpp>
#include <yq/tachyon/thread/NetworkThread.hpp>
#include <yq/tachyon/thread/SimThread.hpp>
#include <yq/tachyon/thread/TaskThread.hpp>
#include <yq/tachyon/thread/ViewerThread.hpp>

#include <yq/vkqt/XThread.hpp>


namespace yq::tachyon {
    int              YApp::s_argCnt = 0;
    char**           YApp::s_argPtr = nullptr;

    YApp::YApp(int argc, char* argv[], const AppCreateInfo& aci) : Application(argc, argv, aci)
    {
        s_argCnt    = argc;
        s_argPtr    = argv;
    }

    YApp::~YApp()
    {
    }

    bool YApp::start() 
    {
        if(!m_cInfo.thread.app){
            m_cInfo.thread.app      = [](Application& app) -> Ref<AppThread> {
                return new YAppThread(s_argCnt, s_argPtr, app);
            };
        }
        if(!m_cInfo.thread.audio.create){
            m_cInfo.thread.audio.create     = [](Application&) -> Ref<AudioThread>{
                return new XThread<AudioThread>;
            };
        }
        if(!m_cInfo.thread.auxillary.create){
            m_cInfo.thread.auxillary.create = [](Application&) -> Ref<AuxillaryThread>{
                return new XThread<AuxillaryThread>;
            };
        }
        if(!m_cInfo.thread.edit.create){
            m_cInfo.thread.edit.create = [](Application&) -> Ref<EditThread>{
                return new XThread<EditThread>;
            };
        }
        if(!m_cInfo.thread.game.create){
            m_cInfo.thread.game.create = [](Application&) -> Ref<GameThread>{
                return new XThread<GameThread>;
            };
        }
        if(!m_cInfo.thread.io.create){
            m_cInfo.thread.io.create = [](Application&) -> Ref<IOThread>{
                return new XThread<IOThread>;
            };
        }
        if(!m_cInfo.thread.network.create){
            m_cInfo.thread.network.create = [](Application&) -> Ref<NetworkThread>{
                return new XThread<NetworkThread>;
            };
        }
        if(!m_cInfo.thread.sim.create){
            m_cInfo.thread.sim.create = [](Application&) -> Ref<SimThread>{
                return new XThread<SimThread>;
            };
        }
        if(!m_cInfo.thread.task.create){
            m_cInfo.thread.task.create = [](Application&) -> Ref<TaskThread>{
                return new XThread<TaskThread>;
            };
        }
        if(!m_cInfo.thread.viewer.create){
            m_cInfo.thread.viewer.create = [](Application&) -> Ref<ViewerThread>{
                return new XThread<ViewerThread>;
            };
        }
    
        if(!Application::start())   
            return false;
        m_thread.app -> leak(); // m_appThread = m_thread.app;
        return true;
    }
}

