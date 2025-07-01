////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/keyboard/KeyPressEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {

    KeyPressEvent::KeyPressEvent(const Header& h, ModifierKeys mk, int scanCode, KeyCode key_) : 
        KeyboardEvent(h, mk), m_scan(scanCode), m_key(key_)
    {
    }
    
    KeyPressEvent::KeyPressEvent(const KeyPressEvent& cp, const Header& h) : 
        KeyboardEvent(cp, h), m_scan(cp.m_scan), m_key(cp.m_key)
    {
    }
    
    KeyPressEvent::~KeyPressEvent()
    {
    }

    PostCPtr    KeyPressEvent::clone(rebind_k, const Header&h) const 
    {
        return new KeyPressEvent(*this, h);
    }
    
    void KeyPressEvent::init_info()
    {
        auto w = writer<KeyPressEvent>();
        w.description("Key Press Event");
        w.property("key", &KeyPressEvent::m_key).description("Key code").tag(kTag_Log).tag(kTag_Save);
        w.property("scancode", &KeyPressEvent::m_scan).description("O/S scan code").tag(kTag_Log).tag(kTag_Save);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyPressEvent)

