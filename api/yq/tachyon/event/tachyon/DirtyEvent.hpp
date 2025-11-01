////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/TachyonEvent.hpp>

namespace yq::tachyon {
    class DirtyEvent : public TachyonEvent {
        YQ_OBJECT_DECLARE(DirtyEvent, TachyonEvent)
    public:
        DirtyEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        DirtyEvent(const DirtyEvent&, const Header&);
        virtual ~DirtyEvent();
        
    private:

        DirtyEvent(const DirtyEvent&) = delete;
        DirtyEvent(DirtyEvent&&) = delete;
        DirtyEvent& operator=(const DirtyEvent&) = delete;
        DirtyEvent& operator=(DirtyEvent&&) = delete;
    };
}
