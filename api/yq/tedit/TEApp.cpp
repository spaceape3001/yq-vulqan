////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEApp.hpp"
#include "TEAppThread.hpp"
#include <yq/tachyon/logging.hpp>

namespace yq::tachyon {
    TEApp*   TEApp::s_app = nullptr;

    TEApp::TEApp(int argc, char* argv[], const AppCreateInfo& aci) : YApp(argc, argv, aci)
    {
    }
    
    TEApp::~TEApp()
    {
    }

    bool    TEApp::start() 
    {
        if(!m_cInfo.thread.app){
            m_cInfo.thread.app      = [](Application& app) -> Ref<AppThread> {
                return new TEAppThread(s_argCnt, s_argPtr, app);
            };
        }
    
        return YApp::start();
    }
}

