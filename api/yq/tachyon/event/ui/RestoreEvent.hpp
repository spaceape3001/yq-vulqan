////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/UIEvent.hpp>

namespace yq::tachyon {
    class RestoreEvent : public UIEvent {
        YQ_OBJECT_DECLARE(RestoreEvent, UIEvent)
    public:
        RestoreEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        RestoreEvent(const RestoreEvent&, const Header&);
        virtual ~RestoreEvent();
        
    private:

        RestoreEvent(const RestoreEvent&) = delete;
        RestoreEvent(RestoreEvent&&) = delete;
        RestoreEvent& operator=(const RestoreEvent&) = delete;
        RestoreEvent& operator=(RestoreEvent&&) = delete;
    };
}
