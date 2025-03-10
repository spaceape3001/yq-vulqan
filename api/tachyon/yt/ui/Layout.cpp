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
#include <yq/container/map_utils.hpp>

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
        
        using rev_map_t     = std::map<WidgetID, uint64_t>;
        using value_t       = rev_map_t::value_type;
        
        TickAPI                         ticker{ ctx };
        rev_map_t    newRevs;
        
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        
        const WidgetSnap*   sn  = frame->snap(m_widget);
        if(!sn) 
            return ;
        ticker.widget       = sn;
        for(TypedID ch : sn->children){
            if(!ch(Type::Widget))
                continue;
                
            WidgetID    wid(ch);
            const WidgetSnap*   ws  = frame->snap(wid);
            if(!ws)
                continue;
            
            newRevs[wid]    = ws->revision;
            ticker.children.push_back(ws);
        }
        
        map_difference_exec2(m_revisions, newRevs, 
            [&](const value_t& itr){     // removes
                ticker.removed.insert(itr.first);
            },
            [&](const value_t& itr){     // changes
                ticker.changed.insert(itr.first);
            },
            [&](const value_t& itr){     // same
                ticker.same.insert(itr.first);
            },
            [&](const value_t& itr){
                ticker.added.insert(itr.first);
            }
        );
        m_revisions = newRevs;
        
        tick(ticker);
    }

}

