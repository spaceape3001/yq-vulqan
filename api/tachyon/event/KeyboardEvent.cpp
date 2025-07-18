////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/KeyboardEvent.hpp>

#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyboardEvent)

namespace yq::tachyon {
    KeyboardEvent::KeyboardEvent(const Header&h, ModifierKeys mk) : InputEvent(h, mk)
    {
    }

    KeyboardEvent::KeyboardEvent(const KeyboardEvent& cp, const Header& h) : InputEvent(cp, h)
    {
    }
    
    KeyboardEvent::~KeyboardEvent()
    {
    }


    ////////////////////////////////////////////////////////////////////////////

    void KeyboardEvent::init_meta()
    {
        {
            auto w = writer<KeyboardEvent>();
            w.description("Keyboard event base class");
        }
    }
}
