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
        //Ref<AppThread>          m_appThread;
    };

}

