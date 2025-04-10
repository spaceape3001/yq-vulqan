////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    /*! \brief Base class to "windows" within ImGui
    */
    class UIWindow : public UIElements {
        YQ_OBJECT_DECLARE(UIWindow, UIElements)
    public:
        UIWindow(std::string_view, UIFlags flags={});
        UIWindow(const UIWindow&);
        ~UIWindow();
        
        
        using UIElements::render;
        void        render();
        virtual const char*   title() const override;

        using UIElements::viewport;
        virtual AxBox2F viewport() const override;

        const Vector2F&    pivot() const { return m_pivot; }
        
        static void init_info();

    protected:
        std::string         m_title;
        Vector2F            m_pivot     = { 0., 0. };
        Vector2F            m_position  = { 0., 0. };
        Size2F              m_size      = { 0., 0. };
        Vector2F            m_actualPos;    //!< Measured position
        Vector2F            m_actualSize;   //!< Measured size
        ImGuiWindowFlags    m_imFlags = ImGuiWindowFlags_None;
        
        UIWindow*           clone() const;

        void                update(flags_k) override;
        
        //! Notification that we've gone "closed"
        virtual void    closing() {}
    };
}
