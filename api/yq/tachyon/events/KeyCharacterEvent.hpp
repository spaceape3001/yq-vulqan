////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/KeyboardEvent.hpp>

namespace yq::tachyon {

    /*! \brief Keyboard Character Event
    
        \note This is unicode character!
    */
    class KeyCharacterEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyCharacterEvent, KeyboardEvent)
    public:
    
        struct Param : public KeyboardEvent::Param {
            char32_t    code    = 0;
        };
    
        KeyCharacterEvent(Window*, const Param&);
        KeyCharacterEvent(WindowID, const Param&);
        
        char32_t        code() const { return m_code; }
        
        virtual ~KeyCharacterEvent();
        
        static void init_info();
        
    private:
        const char32_t  m_code;
    };
}
