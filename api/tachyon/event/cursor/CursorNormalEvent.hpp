////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/CursorEvent.hpp>

namespace yq::tachyon {

    /*! \brief Emitted when cursor/mouse is set to "normal" mode
    */
    class CursorNormalEvent : public CursorEvent {
        YQ_OBJECT_DECLARE(CursorNormalEvent, CursorEvent)
    public:
    
        CursorNormalEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
    
    protected:
        CursorNormalEvent(const CursorNormalEvent&, const Header&);
        virtual ~CursorNormalEvent();

    private:
        CursorNormalEvent(const CursorNormalEvent&) = delete;
        CursorNormalEvent(CursorNormalEvent&&) = delete;
        CursorNormalEvent& operator=(const CursorNormalEvent&) = delete;
        CursorNormalEvent& operator=(CursorNormalEvent&&) = delete;
    };
}
