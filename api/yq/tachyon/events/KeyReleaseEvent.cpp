////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyReleaseEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {

    KeyReleaseEvent::KeyReleaseEvent(Window*w, const Param& p) : KeyboardEvent(w, p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyReleaseEvent::KeyReleaseEvent(WindowID w, const Param& p) : KeyboardEvent(w, p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyReleaseEvent::~KeyReleaseEvent()
    {
    }
    
    void KeyReleaseEvent::init_info()
    {
        auto w = writer<KeyReleaseEvent>();
        w.description("Key Release Event");
        w.property("scancode", &KeyReleaseEvent::scan).description("O/S scan code");
        w.property("key", &KeyReleaseEvent::key).description("Key code");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyReleaseEvent)

