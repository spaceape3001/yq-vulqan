////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/KeyboardEvent.hpp>

namespace yq::tachyon {

    /*! \brief Keyboard Character Event
    
        \note This is unicode character!
    */
    class KeyCharacterEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyCharacterEvent, KeyboardEvent)
    public:
    
        KeyCharacterEvent(const Header&, ModifierKeys, char32_t);
        
        char32_t        code() const { return m_code; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_info();

    protected:
        KeyCharacterEvent(const KeyCharacterEvent&, const Header&);
        virtual ~KeyCharacterEvent();
        
    private:
        char32_t  m_code;
        
        KeyCharacterEvent(const KeyCharacterEvent&) = delete;
        KeyCharacterEvent(KeyCharacterEvent&&) = delete;
        KeyCharacterEvent& operator=(const KeyCharacterEvent&) = delete;
        KeyCharacterEvent& operator=(KeyCharacterEvent&&) = delete;
    };
}
