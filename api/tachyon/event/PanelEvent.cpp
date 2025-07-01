////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QPanelLL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/PanelEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PanelEvent)

namespace yq::tachyon {
    PanelEvent::PanelEvent(const Header& h) : Event(h)
    {
    }
    
    PanelEvent::PanelEvent(const PanelEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    PanelEvent::~PanelEvent()
    {
    }
    
    void PanelEvent::init_info()
    {
        auto w = writer<PanelEvent>();
        w.abstract();
        w.description("Panel Event");
    }
}
