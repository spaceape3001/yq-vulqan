////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Layout.hpp"
#include "LayoutInfoWriter.hpp"
#include <yt/api/Frame.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/ui/WidgetData.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Layout)

namespace yq::tachyon {
    LayoutInfo::LayoutInfo(std::string_view kName, DelegateInfo& pInfo, const std::source_location& sl) :
        DelegateInfo(kName, pInfo, sl)
    {
    }

    void Layout::init_info()
    {
        auto w = writer<Layout>();
        w.description("Abstract Layout");
    }
    
    
    Layout::Layout()
    {
    }
    
    Layout::~Layout()
    {
    }

    void    Layout::set_widget(WidgetID w)
    {
        m_widget    = w;
        m_revisions.clear();
    }

    void    Layout::tick(Widget& callback, const Context&ctx)
    {
        m_callback  = &callback;
        
        TickAPI                         ticker{ ctx };
        std::map<WidgetID, uint64_t>    newRevs;
        
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        
        const WidgetSnap*   sn  = frame->snap(m_widget);
        if(!sn) 
            return ;
            
        for(TypedID ch : sn->children){
            if(!ch(Type::Widget))
                continue;
        }
    }

}

