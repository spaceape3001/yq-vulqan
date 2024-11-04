////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyCharacterEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

namespace yq::tachyon {

    KeyCharacterEvent::KeyCharacterEvent(const Param& p) : KeyboardEvent(p), m_code(p.code)
    {
    }
    
    KeyCharacterEvent::~KeyCharacterEvent()
    {
    }
    
    void KeyCharacterEvent::init_info()
    {
        auto w = writer<KeyCharacterEvent>();
        w.description("Key Character Event");
        w.property("code", &KeyCharacterEvent::code).tag(kTag_Log);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyCharacterEvent)

