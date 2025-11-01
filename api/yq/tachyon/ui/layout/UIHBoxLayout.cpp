////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIHBoxLayout.hpp"
#include "UIHBoxLayoutWriter.hpp"
#include <yq/tachyon/ui/UIGenerator.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/trait/has_nan.hpp>
#include <yq/tachyon/ui/UIStyle.hpp>

#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector2.hxx>
#include <yq/shape/Size2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIHBoxLayout)

namespace yq {
    template Size2<float>::Size2(const Vector2F&);
}

namespace yq::tachyon {
    UIHBoxLayout::UIHBoxLayout(UIFlags flags) : UILayout(flags)
    {
    }
    
    UIHBoxLayout::UIHBoxLayout(const UIHBoxLayout& cp) : UILayout(cp)
    {
    }
    
    UIHBoxLayout::~UIHBoxLayout()
    {
    }
        
    UIHBoxLayout* UIHBoxLayout::clone() const
    {
        return new UIHBoxLayout(*this);
    }

    void    UIHBoxLayout::postadd(UIElement* elem) 
    {
        //elem->flag(SET, UIFlag::AutoResizeX);
        //elem->flag(SET, UIFlag::ResizeX);
        elem->flag(SET, UIFlag::NoDecoration);
    }
        
    void    UIHBoxLayout::render() 
    {
        if(m_flags(UIFlag::Invisible))
            return ;

        AxBox2F box = parent() -> viewport(CONTENT);

        float   excess  = box.hi.x - box.lo.x;
        size_t  cnt     = 0;
        
        for(UIElement* e : m_items){
            UIWindow*win  = dynamic_cast<UIWindow*>(e);
            if(!win)
                continue;
            if(win->flag(UIFlag::Invisible))
                continue;
        
            float   w   = win->width(SPEC);
            if(is_nan(w) || (w <= 0.)){
                ++cnt;
            } else {
                excess -= w;
            }
        }
        
        float per = std::max(excess / (float) cnt, style().window.min_size());
        float x   = box.lo.x;

        for(UIElement* e : m_items){
            UIWindow*win  = dynamic_cast<UIWindow*>(e);
            if(!win)
                continue;
            if(win->flag(UIFlag::Invisible))
                continue;

            float   w   = win->width(SPEC);
            if(is_nan(w) || (w <= 0.)){
                w   = per;
            }
            
            win -> position(SET, NEXT, { x, box.lo.y });
            win -> size(SET, NEXT, { w, box.hi.y - box.lo.y });
            

            win->draw();
            x += w;
        }

        if(x > box.hi.x){
            uiOnceWarning << "HBox layout exceeded viewport width";
        }
    }

    YesNo UIHBoxLayout::acceptable(UIElement* elem)
    {
        return dynamic_cast<UIWindow*>(elem) || dynamic_cast<UIGenerator*>(elem);
    }
    
    void UIHBoxLayout::init_meta()
    {
        auto w = writer<UIHBoxLayout>();
        w.description("Horizontal Box UI Layout");
    }
        
    ////////////////////////////
    
    UIHBoxLayoutWriter::UIHBoxLayoutWriter() = default;
    UIHBoxLayoutWriter::UIHBoxLayoutWriter(const UIHBoxLayoutWriter&) = default;
    UIHBoxLayoutWriter::~UIHBoxLayoutWriter() = default;
    
    UIHBoxLayout* UIHBoxLayoutWriter::element()
    {
        return static_cast<UIHBoxLayout*>(m_ui);
    }
    
    UIHBoxLayoutWriter::UIHBoxLayoutWriter(UIHBoxLayout* ui) : UILayoutWriter(ui)
    {
    }

}
