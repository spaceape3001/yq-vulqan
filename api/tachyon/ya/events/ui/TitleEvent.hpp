////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/UIEvent.hpp>

namespace yq::tachyon {
    class TitleEvent : public UIEvent {
        YQ_OBJECT_DECLARE(TitleEvent, UIEvent)
    public:
        TitleEvent(const Header&, std::string_view szNewTitle);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
        std::string_view    title() const { return m_title; }

    protected:
        TitleEvent(const TitleEvent&, const Header&);
        virtual ~TitleEvent();
        
    private:
        std::string     m_title;

        TitleEvent(const TitleEvent&) = delete;
        TitleEvent(TitleEvent&&) = delete;
        TitleEvent& operator=(const TitleEvent&) = delete;
        TitleEvent& operator=(TitleEvent&&) = delete;
    };
}
