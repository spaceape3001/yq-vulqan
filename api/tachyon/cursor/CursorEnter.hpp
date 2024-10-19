////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/CursorEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class CursorEnter : public CursorEvent {
        YQ_OBJECT_DECLARE(CursorEnter, CursorEvent)
    public:

        //  EVENT TODO
        
        Viewer*     viewer() const { return m_viewer; }
        Widget*     widget() const { return m_widget; }

        CursorEnter(Viewer* v, Widget*w, const Vector2D& pos);
        virtual ~CursorEnter();
    
        const Vector2D&    cursor_position() const { return m_cursor; }
    
    protected:

    private:
        Vector2D const  m_cursor;
    };
}
