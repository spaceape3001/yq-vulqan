////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElement.hpp"
#include "UIElementWriter.hpp"
#include "UIElementInfoWriter.hpp"
#include <cassert>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIStyle.hpp>
#include <yq/shape/AxBox2.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIElement)

namespace yq::tachyon {
    float UIDim::operator()() const
    {
        float   ret = scale * ImGui::GetFrameHeight();
        if(min >= 0.)
            ret = std::max(min, ret);
        if(max >= 0.)
            ret = std::min(max, ret);
        return ret;
    }
    
    float UIDim::operator()(float ret) const
    {
        if(min >= 0.)
            ret = std::max(min, ret);
        if(max >= 0.)
            ret = std::min(max, ret);
        return ret;
    }

    ////////////////////////////

    UIElementInfo::UIElementInfo(std::string_view theName, ObjectInfo& pmeta, const std::source_location& sl) : 
        ObjectInfo(theName, pmeta, sl)
    {
    }

    ////////////////////////////

    thread_local Widget*     UIElement::s_widget     = nullptr;
    thread_local ViContext*  UIElement::s_context    = nullptr;
    UIStyle                  UIElement::s_style;

    void UIElement::init_info()
    {
        auto w = writer<UIElement>();
        w.description("Basic UI Element");
    }

    const UIStyle& UIElement::style()
    {
        return s_style;
    }

    Widget*  UIElement::widget()
    {
        return s_widget;
    }

    
    ////////////////////////////

    UIElement::UIElement(UIFlags flags) : m_flags(flags)
    {
    }
    
    UIElement::UIElement(const UIElement& cp) : m_flags(cp.m_flags)
    {
    }
    
    UIElement::~UIElement()
    {
    }
    
    UIElement*     UIElement::copy() const
    {
        UIElement* ret  = clone();
        if(ret)
            ret -> update(FLAGS);
        return ret;
    }

    void    UIElement::draw()
    {
        render();
    }

    void    UIElement::flag(clear_k, UIFlag f)
    {
        m_flags.clear(f);
        update(FLAGS);
    }
    
    void    UIElement::flag(clear_k, UIFlags f)
    {
        m_flags.clear(f);
        update(FLAGS);
    }

    void    UIElement::flag(set_k, UIFlag f)
    {
        m_flags.set(f);
        update(FLAGS);
    }
    
    void    UIElement::flag(set_k, UIFlags f)
    {
        m_flags.set(f);
        update(FLAGS);
    }

    UIElement*  UIElement::parent()
    {
        return m_parent; 
    }
    
    const UIElement*  UIElement::parent() const
    {
        return m_parent;
    }

    UIElement*  UIElement::root()
    {
        UIElement*  p   = this;
        while(p->m_parent){
            p = p->m_parent;
        }
        return p;
    }
    
    const UIElement* UIElement::root() const
    {
        const UIElement*  p   = this;
        while(p->m_parent){
            p = p->m_parent;
        }
        return p;
    }

    AxBox2F UIElement::viewport() const
    {
        if(m_parent)
            return m_parent -> viewport();
        return ZERO;
    }

    AxBox2F UIElement::viewport(content_k) const
    {
        return viewport();
    }

    ////////////////////////////
    UIElementWriter::UIElementWriter(UIElement* ui) : m_ui(ui) {}

    UIElementWriter::UIElementWriter() = default;
    UIElementWriter::UIElementWriter(const UIElementWriter&) = default;
    UIElementWriter::~UIElementWriter() = default;

    void  UIElementWriter::flag(set_k, UIFlag v)
    {
        if(m_ui)
            m_ui->flag(SET, v);
    }
    
    void  UIElementWriter::flag(set_k, UIFlags v)
    {
        if(m_ui)
            m_ui->flag(SET, v);
    }
    
    void  UIElementWriter::flag(clear_k, UIFlag v)
    {
        if(m_ui)
            m_ui->flag(CLEAR, v);
    }
    
    void  UIElementWriter::flag(clear_k, UIFlags v)
    {
        if(m_ui)
            m_ui->flag(CLEAR, v);
    }
}
