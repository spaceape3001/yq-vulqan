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
    AppCreateInfo    YApp::_threads(int argc, char*argv[], const AppCreateInfo&aci)
    {
        AppCreateInfo   ret = aci;
        
        if(!ret.thread.app){
            ret.thread.app      = [argc, argv](Application& app) -> Ref<AppThread> {
                int n   = argc;
                return new YAppThread(n, argv, app);
            };
        }

        if(!ret.thread.audio.create){
            ret.thread.audio.create     = [](Application&) -> Ref<AudioThread>{
                return new XThread<AudioThread>;
            };
        }
        if(!ret.thread.auxillary.create){
            ret.thread.auxillary.create = [](Application&) -> Ref<AuxillaryThread>{
                return new XThread<AuxillaryThread>;
            };
        }
        if(!ret.thread.edit.create){
            ret.thread.edit.create = [](Application&) -> Ref<EditThread>{
                return new XThread<EditThread>;
            };
        }
        if(!ret.thread.game.create){
            ret.thread.game.create = [](Application&) -> Ref<GameThread>{
                return new XThread<GameThread>;
            };
        }
        if(!ret.thread.io.create){
            ret.thread.io.create = [](Application&) -> Ref<IOThread>{
                return new XThread<IOThread>;
            };
        }
        if(!ret.thread.network.create){
            ret.thread.network.create = [](Application&) -> Ref<NetworkThread>{
                return new XThread<NetworkThread>;
            };
        }
        if(!ret.thread.sim.create){
            ret.thread.sim.create = [](Application&) -> Ref<SimThread>{
                return new XThread<SimThread>;
            };
        }
        if(!ret.thread.task.create){
            ret.thread.task.create = [](Application&) -> Ref<TaskThread>{
                return new XThread<TaskThread>;
            };
        }
        if(!ret.thread.viewer.create){
            ret.thread.viewer.create = [](Application&) -> Ref<ViewerThread>{
                return new XThread<ViewerThread>;
            };
        }
        
        return ret; // HACK... need full thing
    }

    YApp::YApp(int argc, char* argv[], const AppCreateInfo& aci) : Application(argc, argv, _threads(argc, argv, aci))
    {
    }

    YApp::~YApp()
    {
    }
}

