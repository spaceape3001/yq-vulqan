////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseDropEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseDropEvent::MouseDropEvent(Window* w, std::vector<std::string>&& _paths, const Param& p) : 
        MouseEvent(w, p), m_paths(std::move(_paths))
    {
    }
    
    MouseDropEvent::MouseDropEvent(WindowID w, std::vector<std::string>&& _paths, const Param& p) : 
        MouseEvent(w, p), m_paths(std::move(_paths))
    {
    }

    MouseDropEvent::~MouseDropEvent()
    {
    }

    void MouseDropEvent::init_info()
    {
        auto w = writer<MouseDropEvent>();
        w.description("Mouse Drop Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseDropEvent)

