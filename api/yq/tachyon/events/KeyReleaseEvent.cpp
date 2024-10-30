////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyReleaseEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    KeyReleaseEvent::KeyReleaseEvent(const Param& p) : KeyboardEvent(p), m_scan(p.scan), m_key(p.key)
    {
    }
    
    KeyReleaseEvent::~KeyReleaseEvent()
    {
    }
    
    static void reg_key_release()
    {
        auto w = writer<KeyReleaseEvent>();
        w.description("Key Release Event");
        w.property("scancode", &KeyReleaseEvent::scan).description("O/S scan code");
        w.property("key", &KeyReleaseEvent::key).description("Key code");
    }
    
    YQ_INVOKE(reg_key_release();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyReleaseEvent)

