////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QTachyonLL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/TachyonEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonEvent)

namespace yq::tachyon {
    TachyonEvent::TachyonEvent(const Header& h) : Event(h)
    {
    }
    
    TachyonEvent::TachyonEvent(const TachyonEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    TachyonEvent::~TachyonEvent()
    {
    }
    
    void TachyonEvent::init_info()
    {
        auto w = writer<TachyonEvent>();
        w.abstract();
        w.description("Tachyon Event");
    }
}
