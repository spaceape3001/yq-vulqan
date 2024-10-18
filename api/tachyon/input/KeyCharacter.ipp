////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyCharacter.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    KeyCharacter::KeyCharacter(Viewer*v, Widget*w, unsigned int cp) : KeyEvent(v, w), m_codePoint(cp)
    {
    }
    
    KeyCharacter::~KeyCharacter()
    {
    }
    
    static void reg_key_character()
    {
        auto w = writer<KeyCharacter>();
        w.description("Key Character (Codepoint) Event");
    }
    
    YQ_INVOKE(reg_key_character();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyCharacter)

