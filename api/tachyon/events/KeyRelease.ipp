////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyRelease.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    KeyRelease::KeyRelease(const Param& p) : KeyEvent(p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyRelease::~KeyRelease()
    {
    }
    
    static void reg_key_release()
    {
        auto w = writer<KeyRelease>();
        w.description("Key Release Event");
        w.property("scancode", &KeyRelease::scan).description("O/S scan code");
        w.property("key", &KeyRelease::key).description("Key code");
    }
    
    YQ_INVOKE(reg_key_release();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyRelease)

