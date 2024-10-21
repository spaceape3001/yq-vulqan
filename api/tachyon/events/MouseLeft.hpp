////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/CursorEvent.hpp>

namespace yq::tachyon {
    class CursorLeft : public CursorEvent {
        YQ_OBJECT_DECLARE(CursorLeft, CursorEvent)
    public:

        struct Param : public CursorEvent::Param {
        };

        CursorLeft(const Param&);
        virtual ~CursorLeft();
    };
}
