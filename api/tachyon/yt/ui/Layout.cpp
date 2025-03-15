////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Layout.hpp"
#include "LayoutInfoWriter.hpp"

#ifdef NAN
#undef NAN
#endif

#include <yt/1D/Widget1Data.hpp>
#include <yt/2D/Widget2Data.hpp>
#include <yt/3D/Widget3Data.hpp>
#include <yt/4D/Widget4Data.hpp>

#include <yt/api/Frame.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/ui/WidgetData.hpp>
#include <yq/container/map_utils.hpp>
#include <yq/math/DimMapper.hxx>
#include <yq/shape/AxBox1.hxx>
#include <yq/shape/AxBox2.hxx>
#include <yq/shape/AxBox3.hxx>
#include <yq/shape/AxBox4.hxx>

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

    AxBox1D     Layout::aabb1(const WidgetSnap&sn) const
    {
        if(sn.self(Type::Widget¹)){
            return m_dims.map1(static_cast<const Widget¹Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget²)){
            return m_dims.map1(static_cast<const Widget²Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget³)){
            return m_dims.map1(static_cast<const Widget³Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget⁴)){
            return m_dims.map1(static_cast<const Widget⁴Snap&>(sn).aabb);
        } else
            return AxBox1D(NAN);
    }
    
    AxBox2D     Layout::aabb2(const WidgetSnap&sn) const
    {
        if(sn.self(Type::Widget¹)){
            return m_dims.map2(static_cast<const Widget¹Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget²)){
            return m_dims.map2(static_cast<const Widget²Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget³)){
            return m_dims.map2(static_cast<const Widget³Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget⁴)){
            return m_dims.map2(static_cast<const Widget⁴Snap&>(sn).aabb);
        } else
            return AxBox2D(NAN);
    }
    
    AxBox3D     Layout::aabb3(const WidgetSnap&sn) const
    {
        if(sn.self(Type::Widget¹)){
            return m_dims.map3(static_cast<const Widget¹Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget²)){
            return m_dims.map3(static_cast<const Widget²Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget³)){
            return m_dims.map3(static_cast<const Widget³Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget⁴)){
            return m_dims.map3(static_cast<const Widget⁴Snap&>(sn).aabb);
        } else
            return AxBox3D(NAN);
    }
    
    AxBox4D     Layout::aabb4(const WidgetSnap&sn) const
    {
        if(sn.self(Type::Widget¹)){
            return m_dims.map4(static_cast<const Widget¹Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget²)){
            return m_dims.map4(static_cast<const Widget²Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget³)){
            return m_dims.map4(static_cast<const Widget³Snap&>(sn).aabb);
        } else if(sn.self(Type::Widget⁴)){
            return m_dims.map4(static_cast<const Widget⁴Snap&>(sn).aabb);
        } else
            return AxBox4D(NAN);
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

