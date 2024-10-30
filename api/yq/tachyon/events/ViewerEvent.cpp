
////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerEvent)

namespace yq::tachyon {
    ViewerEventInfo::ViewerEventInfo(std::string_view zName, const post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerEvent::ViewerEvent(Viewer* v, const Param& p) : post::Event(p), m_viewer(v)
    {
    }
    
    ViewerEvent::~ViewerEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_vulqan_event()
    {
        {
            auto w = writer<ViewerEvent>();
            w.description("Viewer event base class");
        }
    }
    
    YQ_INVOKE(reg_vulqan_event();)
}
