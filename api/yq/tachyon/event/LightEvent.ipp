////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QLightLL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/LightEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LightEvent)

namespace yq::tachyon {
    LightEvent::LightEvent(const Header& h) : Event(h)
    {
    }
    
    LightEvent::LightEvent(const LightEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    LightEvent::~LightEvent()
    {
    }
    
    void LightEvent::init_meta()
    {
        auto w = writer<LightEvent>();
        w.abstract();
        w.description("Light Event");
    }
}
