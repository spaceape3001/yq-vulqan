////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIAppMain.hpp"
#include "UIMenuBar.hpp"
#include "UIButtonBar.hpp"
#include <tachyon/api/Widget.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/AxBox2.hxx>
#include <tachyon/MyImGui.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include "UIAppMainWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIAppMain)

namespace yq::tachyon {
    void UIAppMain::init_info()
    {
        auto w = writer<UIAppMain>();
        w.description("Main Application UI framework");
    }

    UIAppMain::UIAppMain(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIAppMain::UIAppMain(const UIAppMain& cp) : UIElements(cp)
    {
        for(UIElement* ui : m_items){
            if(dynamic_cast<UIMenuBar*>(ui))
                m_status |= S::MenuBar;
            if(dynamic_cast<UIButtonBar*>(ui))
                m_status |= S::ToolBar;
        }
    }
    
    UIAppMain::~UIAppMain()
    {
    }
    
    UIAppMain* UIAppMain::clone() const
    {
        return new UIAppMain(*this);
    }

    AxBox2F UIAppMain::viewport() const 
    {
        const Widget*w  = widget();
        if(!w)
            return ZERO;
        return AxBox2F( ZERO, { (float) w->width(), (float) w->height() });
    }

    AxBox2F UIAppMain::viewport(content_k) const 
    {
        const Widget*w  = widget();
        if(!w)
            return ZERO;

        float   mb  = 0.;
        if(m_status(S::MenuBar))
            mb += ImGui::GetFrameHeight();
        return AxBox2F( { 0., mb }, { (float) w->width(), (float) w->height() });
    }
}
