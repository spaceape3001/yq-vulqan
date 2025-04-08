////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    /*! \brief Base class to "windows" within ImGui
    */
    class UIWindow : public UIElements {
    public:
        UIWindow(std::string_view, UIFlags flags={ UIFlag::NoSavedSettings });
        UIWindow(const UIWindow&);
        ~UIWindow();
        
        
        using UIElements::render;
        void        render();
        virtual const char*   title() const override;

    protected:
        std::string         m_title;
        Vector2F            m_pivot     = { 0., 0. };
        Vector2F            m_position  = { 0., 0. };
        Size2F              m_size      = { 0., 0. };
        ImGuiWindowFlags    m_imFlags = ImGuiWindowFlags_None;
        
        UIWindow*           clone() const;

        void                update(flags_k) override;
        
        //! Notification that we've gone "closed"
        virtual void    closing() {}
    };
}
