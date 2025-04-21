////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIHBox.hpp"
#include "UIHBoxWriter.hpp"
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

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIHBox)

namespace yq {
    template Size2<float>::Size2(const Vector2F&);
}

namespace yq::tachyon {
    UIHBox::UIHBox(UIFlags flags) : UILayout(flags)
    {
    }
    
    UIHBox::UIHBox(const UIHBox& cp) : UILayout(cp)
    {
    }
    
    UIHBox::~UIHBox()
    {
    }
        
    UIHBox* UIHBox::clone() const
    {
        return new UIHBox(*this);
    }

    void    UIHBox::postadd(UIElement* elem) 
    {
        //elem->flag(SET, UIFlag::AutoResizeX);
        //elem->flag(SET, UIFlag::ResizeX);
        elem->flag(SET, UIFlag::NoDecoration);
    }
        
    void    UIHBox::render() 
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
        
            float   w   = win->width(SPEC);
            if(is_nan(w) || (w <= 0.)){
                ++cnt;
            } else {
                excess -= w;
            }
        }
        
        float per = std::max(excess / (float) cnt, style().window.min_size());
        float x   = box.lo.x;

        size_t n = 1;

        for(UIElement* e : m_items){
            UIWindow*win  = dynamic_cast<UIWindow*>(e);
            if(!win)
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

    YesNo UIHBox::acceptable(UIElement* elem)
    {
        return dynamic_cast<UIWindow*>(elem) || dynamic_cast<UIGenerator*>(elem);
    }
    
    void UIHBox::init_info()
    {
        auto w = writer<UIHBox>();
        w.description("Horizontal Box UI Layout");
    }
        
    ////////////////////////////
    
    UIHBoxWriter::UIHBoxWriter() = default;
    UIHBoxWriter::UIHBoxWriter(const UIHBoxWriter&) = default;
    UIHBoxWriter::~UIHBoxWriter() = default;
    
    UIHBox* UIHBoxWriter::element()
    {
        return static_cast<UIHBox*>(m_ui);
    }
    
    UIHBoxWriter::UIHBoxWriter(UIHBox* ui) : UILayoutWriter(ui)
    {
    }

}
