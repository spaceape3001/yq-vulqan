////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseDropEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    MouseDropEvent::MouseDropEvent(std::vector<std::string>&& _paths, const Param& p) : 
        MouseEvent(p), m_paths(std::move(_paths))
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
    
    YQ_INVOKE(MouseDropEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseDropEvent)

