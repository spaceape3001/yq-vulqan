////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/KeyCharacterEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {

    KeyCharacterEvent::KeyCharacterEvent(WindowID w, const Param& p) : KeyboardEvent(w, p), m_code(p.code)
    {
    }
    
    KeyCharacterEvent::KeyCharacterEvent(Window* w, const Param& p) : KeyboardEvent(w, p), m_code(p.code)
    {
    }
    

    KeyCharacterEvent::~KeyCharacterEvent()
    {
    }
    
    void KeyCharacterEvent::init_info()
    {
        auto w = writer<KeyCharacterEvent>();
        w.description("Key Character Event");
        w.property("code", &KeyCharacterEvent::code).tag(kTag_Log);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyCharacterEvent)

