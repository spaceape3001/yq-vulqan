////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/CursorEvent.hpp>

namespace yq::tachyon {
    class CursorEnter : public CursorEvent {
        YQ_OBJECT_DECLARE(CursorEnter, CursorEvent)
    public:

        struct Param : public CursorEvent::Param {
        };

        CursorEnter(const Param&);
        virtual ~CursorEnter();
    };
}
