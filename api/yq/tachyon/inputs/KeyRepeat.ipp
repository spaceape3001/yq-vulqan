////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyRepeat.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    KeyRepeat::KeyRepeat(const Param& p) : KeyEvent(p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyRepeat::~KeyRepeat()
    {
    }
    
    static void reg_key_press()
    {
        auto w = writer<KeyRepeat>();
        w.description("Key Repeat Event");
        w.property("scancode", &KeyRepeat::scan).description("O/S scan code");
        w.property("key", &KeyRepeat::key).description("Key code");
    }
    
    YQ_INVOKE(reg_key_press();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyRepeat)

