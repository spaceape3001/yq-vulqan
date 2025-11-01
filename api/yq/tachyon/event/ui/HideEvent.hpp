////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/UIEvent.hpp>

namespace yq::tachyon {
    class HideEvent : public UIEvent {
        YQ_OBJECT_DECLARE(HideEvent, UIEvent)
    public:
        HideEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        HideEvent(const HideEvent&, const Header&);
        virtual ~HideEvent();
        
    private:

        HideEvent(const HideEvent&) = delete;
        HideEvent(HideEvent&&) = delete;
        HideEvent& operator=(const HideEvent&) = delete;
        HideEvent& operator=(HideEvent&&) = delete;
    };
}
