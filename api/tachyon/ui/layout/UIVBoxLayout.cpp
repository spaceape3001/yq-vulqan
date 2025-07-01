////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIVBoxLayout.hpp"
#include "UIVBoxLayoutWriter.hpp"
#include <tachyon/ui/UIGenerator.hpp>
#include <tachyon/ui/UIWindow.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/Size2.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/trait/has_nan.hpp>
#include <tachyon/ui/UIStyle.hpp>

#include <tachyon/logging.hpp>
#include <yq/vector/Vector2.hxx>
#include <yq/shape/Size2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIVBoxLayout)

namespace yq {
    template Size2<float>::Size2(const Vector2F&);
}

namespace yq::tachyon {
    UIVBoxLayout::UIVBoxLayout(UIFlags flags) : UILayout(flags)
    {
    }
    
    UIVBoxLayout::UIVBoxLayout(const UIVBoxLayout& cp) : UILayout(cp)
    {
    }
    
    UIVBoxLayout::~UIVBoxLayout()
    {
    }
        
    UIVBoxLayout* UIVBoxLayout::clone() const
    {
        return new UIVBoxLayout(*this);
    }

    void    UIVBoxLayout::postadd(UIElement* elem) 
    {
        //elem->flag(SET, UIFlag::AutoResizeX);
        //elem->flag(SET, UIFlag::ResizeX);
        elem->flag(SET, UIFlag::NoDecoration);
    }
        
    void    UIVBoxLayout::render() 
    {
        if(m_flags(UIFlag::Invisible))
            return ;

        AxBox2F box = parent() -> viewport(CONTENT);

        float   excess  = box.hi.y - box.lo.y;
        size_t  cnt     = 0;
        
        for(UIElement* e : m_items){
            UIWindow*win  = dynamic_cast<UIWindow*>(e);
            if(!win)
                continue;
            if(win->flag(UIFlag::Invisible))
                continue;
        
            float   h   = win->height(SPEC);
            if(is_nan(h) || (h <= 0.)){
                ++cnt;
            } else {
                excess -= h;
            }
        }
        
        float per = std::max(excess / (float) cnt, style().window.min_size());
        float y   = box.lo.y;

        for(UIElement* e : m_items){
            UIWindow*win  = dynamic_cast<UIWindow*>(e);
            if(!win)
                continue;
            if(win->flag(UIFlag::Invisible))
                continue;

            float   h   = win->width(SPEC);
            if(is_nan(h) || (h <= 0.)){
                h   = per;
            }
            
            win -> position(SET, NEXT, { box.lo.x, y });
            win -> size(SET, NEXT, { box.hi.x - box.lo.x, h });
            

            win->draw();
            y += h;
        }

        if(y > box.hi.y){
            uiOnceWarning << "VBox layout exceeded viewport height";
        }
    }

    YesNo UIVBoxLayout::acceptable(UIElement* elem)
    {
        return dynamic_cast<UIWindow*>(elem) || dynamic_cast<UIGenerator*>(elem);
    }
    
    void UIVBoxLayout::init_info()
    {
        auto w = writer<UIVBoxLayout>();
        w.description("Vertical Box UI Layout");
    }
        
    ////////////////////////////
    
    UIVBoxLayoutWriter::UIVBoxLayoutWriter() = default;
    UIVBoxLayoutWriter::UIVBoxLayoutWriter(const UIVBoxLayoutWriter&) = default;
    UIVBoxLayoutWriter::~UIVBoxLayoutWriter() = default;
    
    UIVBoxLayout* UIVBoxLayoutWriter::element()
    {
        return static_cast<UIVBoxLayout*>(m_ui);
    }
    
    UIVBoxLayoutWriter::UIVBoxLayoutWriter(UIVBoxLayout* ui) : UILayoutWriter(ui)
    {
    }

}
