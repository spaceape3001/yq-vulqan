////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
    /*! \brief Widget that's UI centric
    
        Widget whose purpose is ImGui, thus the imgui subcalls won't 
        be required for subclasses
    */
    class WidgetUI : public Widget {
        YQ_TACHYON_DECLARE(WidgetUI, Widget)
    public:
    
        WidgetUI();
        WidgetUI(const Param&);
        ~WidgetUI();
        
        static void init_meta();

        using Widget::imgui;
        void    imgui(ViContext&) override;
        
        Execution setup(const Context&ctx) override;
        Execution tick(const Context&ctx) override;
        Execution teardown(const Context&ctx) override;
        
        std::string_view    title() const override { return m_title; }
        
    private:
        std::string     m_title;
    };
}
