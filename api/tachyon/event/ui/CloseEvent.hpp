////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/UIEvent.hpp>

namespace yq::tachyon {
    class CloseEvent : public UIEvent {
        YQ_OBJECT_DECLARE(CloseEvent, UIEvent)
    public:
        CloseEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        CloseEvent(const CloseEvent&, const Header&);
        virtual ~CloseEvent();
        
    private:

        CloseEvent(const CloseEvent&) = delete;
        CloseEvent(CloseEvent&&) = delete;
        CloseEvent& operator=(const CloseEvent&) = delete;
        CloseEvent& operator=(CloseEvent&&) = delete;
    };
}
