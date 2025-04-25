////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/UIEvent.hpp>

namespace yq::tachyon {
    class IconifyEvent : public UIEvent {
        YQ_OBJECT_DECLARE(IconifyEvent, UIEvent)
    public:
        IconifyEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        IconifyEvent(const IconifyEvent&, const Header&);
        virtual ~IconifyEvent();
        
    private:

        IconifyEvent(const IconifyEvent&) = delete;
        IconifyEvent(IconifyEvent&&) = delete;
        IconifyEvent& operator=(const IconifyEvent&) = delete;
        IconifyEvent& operator=(IconifyEvent&&) = delete;
    };
}
