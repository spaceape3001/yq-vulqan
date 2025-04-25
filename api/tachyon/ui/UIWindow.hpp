////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/trait/has_nan.hpp>

namespace yq::tachyon {
    class UIWindowWriter;
    
    /*! \brief Base class to "windows" within ImGui
    */
    class UIWindow : public UIElements {
        YQ_OBJECT_DECLARE(UIWindow, UIElements)
    public:
        using Writer = UIWindowWriter;

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
        
        float       height() const;
        float       height(actual_k) const;
        float       height(calculate_k) const;
        float       height(next_k) const;
        float       height(specification_k) const;
        float       height(use_k) const;
        
        void        height(set_k, calculate_k, float);
        void        height(set_k, next_k, float);
        void        height(set_k, specification_k, float);

        Vector2F    position() const;
        Vector2F    position(actual_k) const;
        Vector2F    position(calculate_k) const;
        Vector2F    position(next_k) const;
        Vector2F    position(specification_k) const;
        Vector2F    position(use_k) const;
        
        void        position(set_k, calculate_k, Vector2F);
        void        position(set_k, next_k, Vector2F);
        void        position(set_k, specification_k, Vector2F);
        
        Size2F      size() const;
        Size2F      size(actual_k) const;
        Size2F      size(calculate_k) const;
        Size2F      size(next_k) const;
        Size2F      size(specification_k) const;
        Size2F      size(use_k) const;
        
        void        size(set_k, calculate_k, Size2F);
        void        size(set_k, next_k, Size2F);
        void        size(set_k, specification_k, Size2F);

        float       width() const;
        float       width(actual_k) const;
        float       width(calculate_k) const;
        float       width(next_k) const;
        float       width(specification_k) const;
        float       width(use_k) const;
        
        void        width(set_k, calculate_k, float);
        void        width(set_k, next_k, float);
        void        width(set_k, specification_k, float);

        float       x() const;
        float       x(actual_k) const;
        float       x(calculate_k) const;
        float       x(next_k) const;
        float       x(specification_k) const;
        float       x(use_k) const;
        
        void        x(set_k, calculate_k, float);
        void        x(set_k, next_k, float);
        void        x(set_k, specification_k, float);

        float       y() const;
        float       y(actual_k) const;
        float       y(calculate_k) const;
        float       y(next_k) const;
        float       y(specification_k) const;
        float       y(use_k) const;
        
        void        y(set_k, calculate_k, float);
        void        y(set_k, next_k, float);
        void        y(set_k, specification_k, float);

    protected:
        friend class UIWindowWriter;
    
        static constexpr float nanF = nan_v<float>;
    
        std::string         m_title;
        Vector2F            m_pivot         = { 0., 0. };
        
        P<float>            m_x = nanF;
        P<float>            m_y = nanF;
        P<float>            m_w = nanF;
        P<float>            m_h = nanF;
        
        ImGuiWindowFlags    m_imFlags       = ImGuiWindowFlags_None;
        ImGuiChildFlags     m_chFlags       = ImGuiChildFlags_None;
        
        UIWindow*           clone() const;

        void                update(flags_k) override;
        
        //! Notification that we've gone "closed"
        virtual void    closing() {}
    };
}
