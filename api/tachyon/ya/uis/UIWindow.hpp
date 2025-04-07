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

        UIFlags flags() const noexcept { return m_flags; }
        void    flag(set_k, UIFlag);
        void    flag(clear_k, UIFlag);

    protected:
        std::string         m_title;
        Vector2F            m_pivot     = { 0., 0. };
        Vector2F            m_position  = { 0., 0. };
        Vector2F            m_size      = { 0., 0. };
        UIFlags             m_flags;
        ImGuiWindowFlags    m_imFlags = ImGuiWindowFlags_None;
        
        void                update(flags_k);
        
        //! Notification that we've gone "closed"
        virtual void    closing() {}
    };
}
