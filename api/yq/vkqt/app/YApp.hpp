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
    class YApp : public Application {
    public:
    
        YApp(int, char*[], const AppCreateInfo&);
        ~YApp();
        
    private:
        static AppCreateInfo    _threads(int, char*[], const AppCreateInfo&);
    };

}

