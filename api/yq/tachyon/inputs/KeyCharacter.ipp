////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyCharacter.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    KeyCharacter::KeyCharacter(const Param& p) : KeyEvent(p), m_code(p.code)
    {
    }
    
    KeyCharacter::~KeyCharacter()
    {
    }
    
    static void reg_key_character()
    {
        auto w = writer<KeyCharacter>();
        w.description("Key Character Event");
    }
    
    YQ_INVOKE(reg_key_character();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyCharacter)

