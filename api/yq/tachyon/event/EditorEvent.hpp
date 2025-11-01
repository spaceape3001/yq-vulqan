////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {
    class EditorEvent : public Event {
        YQ_OBJECT_DECLARE(EditorEvent, Event)
    public:
    
        static void init_meta();

    protected:
        EditorEvent(const Header&);
        EditorEvent(const EditorEvent&, const Header&);
        virtual ~EditorEvent();
    
    private:
        EditorEvent(const EditorEvent&) = delete;
        EditorEvent(EditorEvent&&) = delete;
        EditorEvent& operator=(const EditorEvent&) = delete;
        EditorEvent& operator=(EditorEvent&&) = delete;
    };
}
