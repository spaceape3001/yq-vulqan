////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIAppMain.hpp"
#include "UIMenuBar.hpp"
#include "UIToolBar.hpp"
#include <yt/ui/Widget.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/AxBox2.hxx>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>
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
            if(dynamic_cast<UIToolBar*>(ui))
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

    ////////////////////////////
    
    UIAppMain*   UIAppMainWriter::attach(Widget* w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui)
            return dynamic_cast<UIAppMain*>(w->m_ui);
        UIAppMain*ret   = new UIAppMain;
        w->m_ui = ret;
        return ret;
    }
    
    UIAppMain*   UIAppMainWriter::attach(WidgetInfo*w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui)
            return dynamic_cast<UIAppMain*>(w->m_ui);
        UIAppMain*ret   = new UIAppMain;
        w->m_ui = ret;
        return ret;
    }

    UIAppMainWriter::UIAppMainWriter() = default;
    UIAppMainWriter::UIAppMainWriter(const UIAppMainWriter&) = default;
    UIAppMainWriter::~UIAppMainWriter() = default;
    
    UIAppMainWriter::UIAppMainWriter(Widget* w) : UIElementsWriter(attach(w))
    {
    }
    
    UIAppMainWriter::UIAppMainWriter(WidgetInfo* wi) : UIElementsWriter(attach(wi))
    {
    }

    UIAppMain* UIAppMainWriter::element()
    {
        return static_cast<UIAppMain*>(m_ui);
    }
    
    UIAppMainWriter::UIAppMainWriter(UIAppMain* ui) : UIElementsWriter(ui)
    {
    }
}
