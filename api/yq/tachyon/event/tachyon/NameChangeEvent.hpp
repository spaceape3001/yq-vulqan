////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/TachyonEvent.hpp>

namespace yq::tachyon {
    class NameChangeEvent : public TachyonEvent {
        YQ_OBJECT_DECLARE(NameChangeEvent, TachyonEvent)
    public:
        NameChangeEvent(const Header&, std::string&&, std::string_view);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        std::string_view    old_name() const { return m_old; }
        std::string_view    new_name() const { return m_new; }

    protected:
        NameChangeEvent(const NameChangeEvent&, const Header&);
        virtual ~NameChangeEvent();
        
    private:
    
        std::string m_old;
        std::string m_new;

        NameChangeEvent(const NameChangeEvent&) = delete;
        NameChangeEvent(NameChangeEvent&&) = delete;
        NameChangeEvent& operator=(const NameChangeEvent&) = delete;
        NameChangeEvent& operator=(NameChangeEvent&&) = delete;
    };
}
