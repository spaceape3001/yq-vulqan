////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MetaSelectionChangedEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MetaSelectionChangedEvent)

namespace yq::tachyon {

    MetaSelectionChangedEvent::MetaSelectionChangedEvent(const Header&h, const Meta* info) : 
        PanelEvent(h), m_meta(info)
    {
    }

    MetaSelectionChangedEvent::MetaSelectionChangedEvent(const MetaSelectionChangedEvent& cp, const Header& h) : 
        PanelEvent(cp, h), m_meta(cp.m_meta)
    {
    }
    
    MetaSelectionChangedEvent::~MetaSelectionChangedEvent()
    {
    }

    PostCPtr    MetaSelectionChangedEvent::clone(rebind_k, const Header&h) const 
    {
        return new MetaSelectionChangedEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MetaSelectionChangedEvent::init_meta()
    {
        auto w = writer<MetaSelectionChangedEvent>();
        w.description("Meta Selection Changed Event");
    }
}
