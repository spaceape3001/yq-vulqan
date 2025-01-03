////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/cursor.hpp>

namespace yq::tachyon {
    class Cursor;

    //! Utiltity to bind a viewer to the whatever...
    class CursorBind {
    public:
        CursorID    cursor() const { return m_cursor; }
        
    protected:
        CursorBind(CursorID v) : m_cursor(v) {}
        CursorBind(const Cursor* v);
        virtual ~CursorBind() {}
        
        CursorID const m_cursor;
    };
}
