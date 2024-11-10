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
    
    using As    = std::variant<std::monostate, AsTachyon, AsViewer, AsWidget, AsWindow>;
    
    constexpr bool    is_tachyon(const As& as)
    {
        return static_cast<bool>(std::get_if<AsTachyon>(&as));
    }

    constexpr bool    is_viewer(const As& as)
    {
        return static_cast<bool>(std::get_if<AsViewer>(&as));
    }

    constexpr bool    is_window(const As& as)
    {
        return static_cast<bool>(std::get_if<AsWindow>(&as));
    }

    constexpr bool    is_widget(const As& as)
    {
        return static_cast<bool>(std::get_if<AsWidget>(&as));
    }
};
