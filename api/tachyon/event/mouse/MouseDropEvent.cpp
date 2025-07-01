////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/mouse/MouseDropEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {

    MouseDropEvent::MouseDropEvent(const Header& h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns, std::vector<std::string>&& _paths) :
        MouseEvent(h, mk, pos, btns), m_paths(std::move(_paths))
    {
    }
    
    MouseDropEvent::MouseDropEvent(const MouseDropEvent& cp, const Header& h) : MouseEvent(cp, h), m_paths(cp.m_paths)
    {
    }

    MouseDropEvent::~MouseDropEvent()
    {
    }

    PostCPtr    MouseDropEvent::clone(rebind_k, const Header& h) const 
    {
        return new MouseDropEvent(*this, h);
    }

    void MouseDropEvent::init_meta()
    {
        auto w = writer<MouseDropEvent>();
        w.description("Mouse Drop Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseDropEvent)

