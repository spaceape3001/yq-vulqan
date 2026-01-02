////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WidgetUI.hpp"
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/command/ui/TitleCommand.hpp>
#include <yq/tachyon/ui/UIElement.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WidgetUI)

namespace yq::tachyon {
    void WidgetUI::init_meta()
    {
        auto w  = writer<WidgetUI>();
        w.abstract();
    }

    WidgetUI::WidgetUI() : WidgetUI(Param())
    {
    }
    
    WidgetUI::WidgetUI(const Param&p) : Widget(p)
    {
    }
    
    WidgetUI::~WidgetUI()
    {
    }
    
    void    WidgetUI::imgui(ViContext& u) 
    {
        Widget::imgui(UI, u);
        Widget::imgui(u);
    }

    Execution WidgetUI::setup(const Context&ctx)
    {
        return Widget::setup(ctx);
    }
    
    Execution WidgetUI::tick(const Context&ctx)
    {
        if(UIElement *uix  = ui_root()){
            if(const char* t = uix -> title()){
                if(std::string_view(t) == (std::string_view) m_title){
                    m_title     =    t;
                }
            }
        }
        
    
        return Widget::tick(ctx);
    }
    
    Execution WidgetUI::teardown(const Context&ctx)
    {
        return Widget::teardown(ctx);
    }
}
