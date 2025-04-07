////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    /*! \brief Base class to "windows" within ImGui
    */
    class UIWindow : public UIElements {
    public:
        UIWindow(std::string_view, UIFlags flags={});
        UIWindow(const UIWindow&);
        ~UIWindow();
        
        UIWindow*   clone() const;
        
        void        render();
        virtual const char*   title() const override;

    private:
        std::string         m_title;
        UIFlags             m_flags;
        ImGuiWindowFlags    m_imFlags = ImGuiWindowFlags_None;
    };
}
