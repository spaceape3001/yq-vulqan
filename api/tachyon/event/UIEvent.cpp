////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/UIEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

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
    
    void UIEvent::init_meta()
    {
        auto w = writer<UIEvent>();
        w.abstract();
        w.description("UI Event");
    }
}
