////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/keyboard/KeyCharacterEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {

    KeyCharacterEvent::KeyCharacterEvent(const Header&h, ModifierKeys mk, char32_t ch) : 
        KeyboardEvent(h, mk), m_code(ch)
    {
    }
    
    KeyCharacterEvent::KeyCharacterEvent(const KeyCharacterEvent& cp, const Header& h) : 
        KeyboardEvent(cp, h), m_code(cp.m_code)
    {
    }
    

    KeyCharacterEvent::~KeyCharacterEvent()
    {
    }
    
    PostCPtr    KeyCharacterEvent::clone(rebind_k, const Header&h) const
    {
        return new KeyCharacterEvent(*this, h);
    }

    void KeyCharacterEvent::init_meta()
    {
        auto w = writer<KeyCharacterEvent>();
        w.description("Key Character Event");
        w.property("code", &KeyCharacterEvent::m_code).tag(kTag_Log).tag(kTag_Save);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyCharacterEvent)

