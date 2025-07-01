////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/UIEvent.hpp>

namespace yq::tachyon {
    class FocusEvent : public UIEvent {
        YQ_OBJECT_DECLARE(FocusEvent, UIEvent)
    public:
        FocusEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        FocusEvent(const FocusEvent&, const Header&);
        virtual ~FocusEvent();
        
    private:

        FocusEvent(const FocusEvent&) = delete;
        FocusEvent(FocusEvent&&) = delete;
        FocusEvent& operator=(const FocusEvent&) = delete;
        FocusEvent& operator=(FocusEvent&&) = delete;
    };
}
