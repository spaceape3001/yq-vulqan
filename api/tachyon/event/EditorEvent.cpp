////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/EditorEvent.hpp>

#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EditorEvent)

namespace yq::tachyon {
    EditorEvent::EditorEvent(const Header&h) : Event(h)
    {
    }
    
    EditorEvent::EditorEvent(const EditorEvent& cp, const Header&h) : Event(cp, h)
    {
    }

    EditorEvent::~EditorEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void EditorEvent::init_info()
    {
        auto w = writer<EditorEvent>();
        w.description("Editor event base class");
    }
}
