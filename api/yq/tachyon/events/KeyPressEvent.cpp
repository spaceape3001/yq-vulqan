////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyPressEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {

    KeyPressEvent::KeyPressEvent(Window* w, const Param& p) : KeyboardEvent(w, p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyPressEvent::KeyPressEvent(WindowID w, const Param& p) : KeyboardEvent(w, p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyPressEvent::~KeyPressEvent()
    {
    }
    
    void KeyPressEvent::init_info()
    {
        auto w = writer<KeyPressEvent>();
        w.description("Key Press Event");
        w.property("key", &KeyPressEvent::key).description("Key code").tag(kTag_Log);
        w.property("scancode", &KeyPressEvent::scan).description("O/S scan code").tag(kTag_Log);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyPressEvent)

