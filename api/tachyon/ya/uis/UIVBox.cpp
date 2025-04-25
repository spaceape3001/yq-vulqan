////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIVBox.hpp"
#include "UIVBoxWriter.hpp"
#include <ya/uis/UIGenerator.hpp>
#include <ya/uis/UIWindow.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/Size2.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>
#include <yq/trait/has_nan.hpp>
#include <yt/ui/UIStyle.hpp>

#include <yt/logging.hpp>
#include <yq/vector/Vector2.hxx>
#include <yq/shape/Size2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIVBox)

namespace yq {
    template Size2<float>::Size2(const Vector2F&);
}

namespace yq::tachyon {
    UIVBox::UIVBox(UIFlags flags) : UILayout(flags)
    {
    }
    
    UIVBox::UIVBox(const UIVBox& cp) : UILayout(cp)
    {
    }
    
    UIVBox::~UIVBox()
    {
    }
        
    UIVBox* UIVBox::clone() const
    {
        return new UIVBox(*this);
    }

    void    UIVBox::postadd(UIElement* elem) 
    {
        //elem->flag(SET, UIFlag::AutoResizeX);
        //elem->flag(SET, UIFlag::ResizeX);
        elem->flag(SET, UIFlag::NoDecoration);
    }
        
    void    UIVBox::render() 
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

    YesNo UIVBox::acceptable(UIElement* elem)
    {
        return dynamic_cast<UIWindow*>(elem) || dynamic_cast<UIGenerator*>(elem);
    }
    
    void UIVBox::init_info()
    {
        auto w = writer<UIVBox>();
        w.description("Vertical Box UI Layout");
    }
        
    ////////////////////////////
    
    UIVBoxWriter::UIVBoxWriter() = default;
    UIVBoxWriter::UIVBoxWriter(const UIVBoxWriter&) = default;
    UIVBoxWriter::~UIVBoxWriter() = default;
    
    UIVBox* UIVBoxWriter::element()
    {
        return static_cast<UIVBox*>(m_ui);
    }
    
    UIVBoxWriter::UIVBoxWriter(UIVBox* ui) : UILayoutWriter(ui)
    {
    }

}
