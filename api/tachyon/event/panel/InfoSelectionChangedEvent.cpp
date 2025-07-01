////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InfoSelectionChangedEvent.hpp"
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InfoSelectionChangedEvent)

namespace yq::tachyon {

    InfoSelectionChangedEvent::InfoSelectionChangedEvent(const Header&h, const TachyonMeta* info) : 
        PanelEvent(h), m_info(info)
    {
    }

    InfoSelectionChangedEvent::InfoSelectionChangedEvent(const InfoSelectionChangedEvent& cp, const Header& h) : 
        PanelEvent(cp, h), m_info(cp.m_info)
    {
    }
    
    InfoSelectionChangedEvent::~InfoSelectionChangedEvent()
    {
    }

    PostCPtr    InfoSelectionChangedEvent::clone(rebind_k, const Header&h) const 
    {
        return new InfoSelectionChangedEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void InfoSelectionChangedEvent::init_info()
    {
        auto w = writer<InfoSelectionChangedEvent>();
        w.description("Info Selection Changed Event");
    }
}
