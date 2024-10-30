////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyPressEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    KeyPressEvent::KeyPressEvent(const Param& p) : KeyboardEvent(p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyPressEvent::~KeyPressEvent()
    {
    }
    
    static void reg_key_press()
    {
        auto w = writer<KeyPressEvent>();
        w.description("Key Press Event");
        w.property("scancode", &KeyPressEvent::scan).description("O/S scan code");
        w.property("key", &KeyPressEvent::key).description("Key code");
    }
    
    YQ_INVOKE(reg_key_press();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyPressEvent)

