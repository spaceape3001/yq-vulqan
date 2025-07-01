////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/CursorEvent.hpp>

namespace yq::tachyon {

    /*! \brief Emitted when cursor/mouse is set to "disable" mode
    */
    class CursorDisableEvent : public CursorEvent {
        YQ_OBJECT_DECLARE(CursorDisableEvent, CursorEvent)
    public:
    
        CursorDisableEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_meta();
    
    protected:
        CursorDisableEvent(const CursorDisableEvent&, const Header&);
        virtual ~CursorDisableEvent();

    private:
        CursorDisableEvent(const CursorDisableEvent&) = delete;
        CursorDisableEvent(CursorDisableEvent&&) = delete;
        CursorDisableEvent& operator=(const CursorDisableEvent&) = delete;
        CursorDisableEvent& operator=(CursorDisableEvent&&) = delete;
    };
}
