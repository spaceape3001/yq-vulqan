////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyPress.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    KeyPress::KeyPress(const Param& p) : KeyEvent(p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyPress::~KeyPress()
    {
    }
    
    static void reg_key_press()
    {
        auto w = writer<KeyPress>();
        w.description("Key Press Event");
        w.property("scancode", &KeyPress::scan).description("O/S scan code");
        w.property("key", &KeyPress::key).description("Key code");
    }
    
    YQ_INVOKE(reg_key_press();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyPress)

