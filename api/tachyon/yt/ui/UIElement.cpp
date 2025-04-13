////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElement.hpp"
#include "UIElementInfoWriter.hpp"
#include <cassert>
#include <yt/api/Action.hpp>
#include <yt/gfx/Texture.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIStyle.hpp>
#include <yt/ui/Widget.hpp>
#include <yv/ViGui.hpp>
#include <yv/ViContext.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/core/Any.hpp>
#include <yt/msg/Post.hpp>

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

    ImTextureID    UIElement::install(const TextureCPtr& tex)
    {
        if(!s_context)
            return nullptr;
        if(!s_context->imgui)
            return nullptr;
        return s_context->imgui->texture(tex);
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
    
    UIElement::UIElement(const UIElement& cp) : m_flags(cp.m_flags), m_bId(cp.m_bId), m_uId(cp.m_uId)
    {
        for(const Action*act : cp.m_actions){
            if(!act)
                continue;
            Action* a   = act->copy();
            if(a)
                m_actions.push_back(a);
        }

        Widget* w = widget();
        if(w)
            w->_insert(this);
    }
    
    UIElement::~UIElement()
    {
        for(const Action* act : m_actions)
            delete act;
        m_actions.clear();

        Widget* w = widget();
        w->_erase(this);
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

    void    UIElement::triggered()
    {
        if(!m_actions.empty()){
            Action::Payload   data;
            data.uielem     = this;
            data.source     = widget();
            for(Action* a : m_actions){
                if(!a)  [[unlikely]]
                    continue;
                a->action(data);
            }
        }
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
}
