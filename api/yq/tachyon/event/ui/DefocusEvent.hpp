////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/UIEvent.hpp>

namespace yq::tachyon {
    class DefocusEvent : public UIEvent {
        YQ_OBJECT_DECLARE(DefocusEvent, UIEvent)
    public:
        DefocusEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        DefocusEvent(const DefocusEvent&, const Header&);
        virtual ~DefocusEvent();
        
    private:

        DefocusEvent(const DefocusEvent&) = delete;
        DefocusEvent(DefocusEvent&&) = delete;
        DefocusEvent& operator=(const DefocusEvent&) = delete;
        DefocusEvent& operator=(DefocusEvent&&) = delete;
    };
}
