////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyPressEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

namespace yq::tachyon {

    KeyPressEvent::KeyPressEvent(const Param& p) : KeyboardEvent(p), m_scan(p.scan), m_key(p.key)
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

