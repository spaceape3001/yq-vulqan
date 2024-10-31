////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerResizeEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerResizeEvent)

namespace yq::tachyon {

    ViewerResizeEvent::ViewerResizeEvent(Viewer* v, const Size2I& sz, const Param& p) : ViewerEvent(v, p), m_size(sz)
    {
    }
    
    ViewerResizeEvent::~ViewerResizeEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerResizeEvent::init_info()
    {
        auto w = writer<ViewerResizeEvent>();
        w.description("Viewer Move Event");
        w.property("width", &ViewerResizeEvent::width).description("Viewer Window's new width").tag(kTag_Log);
        w.property("height", &ViewerResizeEvent::height).description("Viewer Window's new height").tag(kTag_Log);
        w.property("size", &ViewerResizeEvent::size).description("Viewer Window's new size");
    }
    
    YQ_INVOKE(ViewerResizeEvent::init_info();)
}
