////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/widgets/StackedWidget.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    Widget*         StackedWidget::active() 
    {
        if(m_active < m_children.size())
            return m_children[m_active];
        return nullptr;
    }
    
    const Widget*   StackedWidget::active() const
    {
        if(m_active < m_children.size())
            return m_children[m_active];
        return nullptr;
    }

    void            StackedWidget::set_active(size_t v)
    {
        m_active        = v;
    }
    
    void    StackedWidget::imgui_(ViContext&ctx) 
    {
        Widget*w    = active();
        if(w)
            w -> imgui_(ctx);
    }
    
    void    StackedWidget::vulkan_(ViContext&ctx) 
    {
        Widget*w    = active();
        if(w)
            w -> vulkan_(ctx);
    }

    StackedWidget::StackedWidget() = default;
    StackedWidget::~StackedWidget() = default;
    
    void StackedWidget::init_info()
    {
        auto w = writer<StackedWidget>();
        w.description("Stacked, as in one widget at a time");
    }
}


YQ_TACHYON_IMPLEMENT(yq::tachyon::StackedWidget)
