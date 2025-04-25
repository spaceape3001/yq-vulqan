////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/keyboard/KeyReleaseEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

namespace yq::tachyon {

    KeyReleaseEvent::KeyReleaseEvent(const Header& h, ModifierKeys mk, int scanCode, KeyCode key_) : 
        KeyboardEvent(h, mk), m_scan(scanCode), m_key(key_)
    {
    }
    
    KeyReleaseEvent::KeyReleaseEvent(const KeyReleaseEvent& cp, const Header& h) : 
        KeyboardEvent(cp, h), m_scan(cp.m_scan), m_key(cp.m_key)
    {
    }
    
    KeyReleaseEvent::~KeyReleaseEvent()
    {
    }

    PostCPtr    KeyReleaseEvent::clone(rebind_k, const Header&h) const 
    {
        return new KeyReleaseEvent(*this, h);
    }
    
    void KeyReleaseEvent::init_info()
    {
        auto w = writer<KeyReleaseEvent>();
        w.description("Key Release Event");
        w.property("key", &KeyReleaseEvent::m_key).description("Key code").tag(kTag_Log).tag(kTag_Save);
        w.property("scancode", &KeyReleaseEvent::m_scan).description("O/S scan code").tag(kTag_Log).tag(kTag_Save);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyReleaseEvent)

