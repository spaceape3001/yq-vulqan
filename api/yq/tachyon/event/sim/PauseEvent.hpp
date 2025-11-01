////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SimEvent.hpp>

namespace yq::tachyon {
    class PauseEvent : public SimEvent {
        YQ_OBJECT_DECLARE(PauseEvent, SimEvent)
    public:
        PauseEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        PauseEvent(const PauseEvent&, const Header&);
        virtual ~PauseEvent();
        
    private:

        PauseEvent(const PauseEvent&) = delete;
        PauseEvent(PauseEvent&&) = delete;
        PauseEvent& operator=(const PauseEvent&) = delete;
        PauseEvent& operator=(PauseEvent&&) = delete;
    };
}
