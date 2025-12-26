////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElement.hpp"
#include "UIElementMetaWriter.hpp"
#include <cassert>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Action.hpp>
#include <yq/tachyon/api/Gesture.hpp>
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/ui/UIStyle.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/vulkan/ViGui.hpp>
#include <yq/tachyon/vulkan/ViContext.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/core/Any.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <filesystem>
#include <yq/tachyon/raster/DebugRasters.hpp>
#include <yq/tachyon/logging.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIElement)

/*
    Point of consideration...moving UI elements between 
    widgets/viewers, especially when those widgets/viewers
    might be in separate threads.
*/

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

    struct UIElementMeta::Repo {
        std::vector<const UIElementMeta*>   all;
    };
    
    UIElementMeta::Repo& UIElementMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    const std::vector<const UIElementMeta*>& UIElementMeta::all()
    {
        return repo().all;
    }

    ////////////////////////////

    UIElementMeta::UIElementMeta(std::string_view theName, ObjectMeta& pmeta, const std::source_location& sl) : 
        ObjectMeta(theName, pmeta, sl)
    {
        repo().all.push_back(this);
    }

    ////////////////////////////

    thread_local Widget*            UIElement::s_widget     = nullptr;
    thread_local ViContext*         UIElement::s_viContext  = nullptr;
    thread_local const Context*     UIElement::s_context    = nullptr;
    UIStyle                         UIElement::s_style;

    std::string      UIElement::alternative(std::string_view sv)
    {
        std::filesystem::path   path(sv);
        return path.filename().stem().string();
    }

    UIElement*       UIElement::element(first_k, uint64_t bId)
    {
        if(!s_widget)
            return nullptr;
        return s_widget -> element(FIRST, bId);
    }
    
    UIElement*       UIElement::element(first_k, const std::string& uId)
    {
        if(!s_widget)   
            return nullptr;
        return s_widget -> element(FIRST, uId);
    }

    void  UIElement::gesture(GestureUPtr&&g)
    {
        if(s_widget)
            s_widget -> gesture(ADD, std::move(g));
    }

    void UIElement::init_meta()
    {
        auto w = writer<UIElement>();
        w.description("Basic UI Element");
    }

    TextureID    UIElement::install(const TextureCPtr& tex)
    {
        if(!s_viContext)
            return {};
        if(!s_viContext->imgui)
            return {};
        return s_viContext->imgui->texture(tex);
    }

    void           UIElement::mail(const PostCPtr& pp)
    {
        if(s_widget)
            s_widget -> mail(pp);
    }

    TextureCPtr    UIElement::missing_texture()
    {
        static TextureCPtr  s_ret   = new Texture(debug::raster_missing());
        return s_ret;
    }

    void           UIElement::send(const PostCPtr& pp)
    {
        if(s_widget)
            s_widget -> send(pp, TARGET);
    }

    const UIStyle& UIElement::style()
    {
        return s_style;
    }

    TextureCPtr      UIElement::texture(std::string_view path)
    {
        return Texture::IO::load(path);
    }

    Widget*  UIElement::widget()
    {
        return s_widget;
    }

    
    ////////////////////////////

    UIElement::UIElement(UIFlags flags) : m_flags(flags)
    {
    }
    
    UIElement::UIElement(const UIElement& cp) : m_flags(cp.m_flags), m_bId(cp.m_bId), m_uId(cp.m_uId), m_actions(cp.m_actions)
    {
        Widget* w = widget();
        if(w)
            w->_insert(this);
    }
    
    UIElement::~UIElement()
    {
        m_actions.clear();
        Widget* w = widget();
        if(w)
            w->_erase(this);
    }
    
    size_t         UIElement::actions(count_k) const
    {
        return m_actions.size();
    }
    
    bool           UIElement::actions(has_k) const
    {
        return !m_actions.empty();
    }

    uint64_t       UIElement::binding(create_k)
    {
        if(!m_bId){
            static std::atomic<uint64_t> s_nextId{1};
            m_bId   = s_nextId++;

            Widget* w = widget();
            if(w)
                w->_insert(this);
        }
        return m_bId;
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

    bool    UIElement::flag(UIFlag v) const 
    { 
        return m_flags(v); 
    }

    void    UIElement::flag(clear_k, UIFlag f)
    {
        m_flags.clear(f);
        update(FLAGS);
    }
    
    void    UIElement::flag(set_k, UIFlag f)
    {
        m_flags.set(f);
        update(FLAGS);
    }
    
    void    UIElement::flag(set_k, UIFlag f, bool v)
    {
        m_flags.set(f, v);
    }

    void    UIElement::flags(clear_k, UIFlags f)
    {
        m_flags.clear(f);
        update(FLAGS);
    }

    void    UIElement::flags(set_k, UIFlags f)
    {
        m_flags.set(f);
        update(FLAGS);
    }

    void        UIElement::flag(toggle_k, UIFlag f)
    {
        m_flags.toggle(f);
        update(FLAGS);
    }

    bool    UIElement::invisible() const
    {
        return m_flags(UIFlag::Invisible);
    }

    Tristate    UIElement::is(const UIElementMeta& baseInfo) const
    {
        return (metaInfo().is_base(baseInfo) || metaInfo().is_this(baseInfo)) ? Tristate::YES : Tristate::NO;
    }

    UIElement*  UIElement::parent()
    {
        return m_parent; 
    }
    
    const UIElement*  UIElement::parent() const
    {
        return m_parent;
    }

    Payload     UIElement::payload()
    {   
        return Payload({ .source=widget(), .uielem=this });
    }

    bool        UIElement::readonly() const
    {
        return m_flags(UIFlag::ReadOnly);
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
        Payload payload;
        triggered(payload);
    }

    void    UIElement::triggered(Payload& payload)
    {
        if(!m_actions.empty()){
            payload.m_uielem     = this;
            payload.m_source     = widget();
            for(auto& a : m_actions){
                if(!a)  [[unlikely]]
                    continue;
                a->action(payload);
            }
        }
    }

    void    UIElement::triggered(Payload&& payload)
    {
        if(!m_actions.empty()){
            payload.m_uielem     = this;
            payload.m_source     = widget();
            for(auto& a : m_actions){
                if(!a)  [[unlikely]]
                    continue;
                a->action(payload);
            }
            payload             = {};
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
