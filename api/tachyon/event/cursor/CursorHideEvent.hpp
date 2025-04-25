////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/CursorEvent.hpp>

namespace yq::tachyon {

    /*! \brief Emitted when cursor/mouse is set to "hidden" mode
    */
    class CursorHideEvent : public CursorEvent {
        YQ_OBJECT_DECLARE(CursorHideEvent, CursorEvent)
    public:
    
        CursorHideEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
    
    protected:
        CursorHideEvent(const CursorHideEvent&, const Header&);
        virtual ~CursorHideEvent();

    private:
        CursorHideEvent(const CursorHideEvent&) = delete;
        CursorHideEvent(CursorHideEvent&&) = delete;
        CursorHideEvent& operator=(const CursorHideEvent&) = delete;
        CursorHideEvent& operator=(CursorHideEvent&&) = delete;
    };
}
