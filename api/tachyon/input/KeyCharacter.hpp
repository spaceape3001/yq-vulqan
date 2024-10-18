////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class KeyCharacter : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyCharacter, KeyboardEvent)
    public:
        KeyCharacter(Viewer*, Widget*, unsigned int);
        
        unsigned int        code_point() const { return m_codePoint; }
        
        virtual ~KeyCharacter();
        
    private:
        const unsigned int    m_codePoint;
    };
}
