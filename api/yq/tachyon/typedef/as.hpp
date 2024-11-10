////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>

namespace yq::tachyon {
    class Viewer;
    class Widget;
    class Tachyon;
    class Camera;
    
    struct AsCamera {
        Camera*     camera      = nullptr;
    };
    struct AsViewer {
        Viewer*     viewer      = nullptr;
    };
    struct AsWindow {
        Viewer*     viewer      = nullptr;
    };
    struct AsWidget {
        Widget*     widget      = nullptr;
    };
    struct AsTachyon {
        Tachyon*    tachyon     = nullptr;
    };
    
    using As    = std::variant<std::monostate, AsCamera, AsTachyon, AsViewer, AsWidget, AsWindow>;
};
