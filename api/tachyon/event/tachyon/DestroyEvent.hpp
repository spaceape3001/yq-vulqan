////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/TachyonEvent.hpp>

namespace yq::tachyon {
    class DestroyEvent : public TachyonEvent {
        YQ_OBJECT_DECLARE(DestroyEvent, TachyonEvent)
    public:
        DestroyEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        DestroyEvent(const DestroyEvent&, const Header&);
        virtual ~DestroyEvent();
        
    private:

        DestroyEvent(const DestroyEvent&) = delete;
        DestroyEvent(DestroyEvent&&) = delete;
        DestroyEvent& operator=(const DestroyEvent&) = delete;
        DestroyEvent& operator=(DestroyEvent&&) = delete;
    };
}
