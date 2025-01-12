////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/UIEvent.hpp>

namespace yq::tachyon {
    class ShowEvent : public UIEvent {
        YQ_OBJECT_DECLARE(ShowEvent, UIEvent)
    public:
        ShowEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        ShowEvent(const ShowEvent&, const Header&);
        virtual ~ShowEvent();
        
    private:

        ShowEvent(const ShowEvent&) = delete;
        ShowEvent(ShowEvent&&) = delete;
        ShowEvent& operator=(const ShowEvent&) = delete;
        ShowEvent& operator=(ShowEvent&&) = delete;
    };
}
