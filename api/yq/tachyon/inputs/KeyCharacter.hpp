////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/KeyEvent.hpp>

namespace yq::tachyon {
    class KeyCharacter : public KeyEvent {
        YQ_OBJECT_DECLARE(KeyCharacter, KeyEvent)
    public:
    
        struct Param : public KeyEvent::Param {
            unsigned int    code    = 0;
        };
    
        KeyCharacter(const Param&);
        
        unsigned int        code() const { return m_codePoint; }
        
        virtual ~KeyCharacter();
        
    private:
        unsigned int    m_code;
    };
}
