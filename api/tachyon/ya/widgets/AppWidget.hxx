////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "AppWidget.hpp"

namespace yq::tachyon {
    struct AppItem {
        const char* name        = "";
        const char* shortcut    = "";
    };

    struct AppMenuItem : public AppItem {
        
    };
    
    struct AppMenu : public AppItem {
        
    };
}
