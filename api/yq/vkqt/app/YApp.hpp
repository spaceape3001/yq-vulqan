////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/thread/AppThread.hpp>
#include <yq/gluon/app/Application.hpp>

namespace yq::tachyon {
    class AppThread;
    class YApp : public Application {
    public:
    
        YApp(int, char*[], const AppCreateInfo&);
        ~YApp();
        
        virtual bool start() override;
        
    private:
        static AppCreateInfo    _threads(int, char*[], const AppCreateInfo&);
        static int              s_argCnt;
        static char**           s_argPtr;
        //Ref<AppThread>          m_appThread;
    };

}

