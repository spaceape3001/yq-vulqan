////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/CursorEvent.hpp>

namespace yq::tachyon {

    /*! \brief Emitted when cursor/mouse is set to "capture" mode
    */
    class CursorCaptureEvent : public CursorEvent {
        YQ_OBJECT_DECLARE(CursorCaptureEvent, CursorEvent)
    public:
    
        CursorCaptureEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
    
    protected:
        CursorCaptureEvent(const CursorCaptureEvent&, const Header&);
        virtual ~CursorCaptureEvent();

    private:
        CursorCaptureEvent(const CursorCaptureEvent&) = delete;
        CursorCaptureEvent(CursorCaptureEvent&&) = delete;
        CursorCaptureEvent& operator=(const CursorCaptureEvent&) = delete;
        CursorCaptureEvent& operator=(CursorCaptureEvent&&) = delete;
    };
}
