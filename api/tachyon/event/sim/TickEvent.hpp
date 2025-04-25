////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SimEvent.hpp>

namespace yq::tachyon {
    class TickEvent : public SimEvent {
        YQ_OBJECT_DECLARE(TickEvent, SimEvent)
    public:
        TickEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        TickEvent(const TickEvent&, const Header&);
        virtual ~TickEvent();
        
    private:

        TickEvent(const TickEvent&) = delete;
        TickEvent(TickEvent&&) = delete;
        TickEvent& operator=(const TickEvent&) = delete;
        TickEvent& operator=(TickEvent&&) = delete;
    };
}
