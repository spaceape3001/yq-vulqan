////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/UIEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIEvent)

namespace yq::tachyon {
    UIEvent::UIEvent(const Header& h) : Event(h)
    {
    }
    
    UIEvent::UIEvent(const UIEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    UIEvent::~UIEvent()
    {
    }
    
    void UIEvent::init_info()
    {
        auto w = writer<UIEvent>();
        w.abstract();
        w.description("UI Event");
    }
}
