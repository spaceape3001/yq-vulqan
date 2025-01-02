////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyRepeatEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    KeyRepeatEvent::KeyRepeatEvent(Window*w, const Param& p) : KeyboardEvent(w, p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyRepeatEvent::KeyRepeatEvent(WindowID w, const Param& p) : KeyboardEvent(w, p), m_scan(p.scan), m_key(p.key)
    {
    }

    KeyRepeatEvent::~KeyRepeatEvent()
    {
    }
    
    void KeyRepeatEvent::init_info()
    {
        auto w = writer<KeyRepeatEvent>();
        w.description("Key Repeat Event");
        w.property("key", &KeyRepeatEvent::key).description("Key code").tag(kTag_Log);
        w.property("scancode", &KeyRepeatEvent::scan).description("O/S scan code").tag(kTag_Log);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyRepeatEvent)

