////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/keyboard/KeyRepeatEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    KeyRepeatEvent::KeyRepeatEvent(const Header&h, ModifierKeys mk, int scan, KeyCode key) : 
        KeyboardEvent(h, mk), m_scan(scan), m_key(key)
    {
    }
    
    KeyRepeatEvent::KeyRepeatEvent(const KeyRepeatEvent&cp, const Header&h) : 
        KeyboardEvent(cp, h), m_scan(cp.m_scan), m_key(cp.m_key)
    {
    }

    KeyRepeatEvent::~KeyRepeatEvent()
    {
    }
    
    PostCPtr    KeyRepeatEvent::clone(rebind_k, const Header&h) const
    {
        return new KeyRepeatEvent(*this, h);
    }

    void KeyRepeatEvent::init_meta()
    {
        auto w = writer<KeyRepeatEvent>();
        w.description("Key Repeat Event");
        w.property("key", &KeyRepeatEvent::m_key).description("Key code").tag(kTag_Log).tag(kTag_Save);
        w.property("scancode", &KeyRepeatEvent::m_scan).description("O/S scan code").tag(kTag_Log).tag(kTag_Save);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyRepeatEvent)

