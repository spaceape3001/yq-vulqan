////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonEvent)

namespace yq::tachyon {
    TachyonEventInfo::TachyonEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    TachyonEvent::TachyonEvent(Tachyon* v, const Param& p) : post::Event(p), TachyonBind(v)
    {
    }
    
    TachyonEvent::~TachyonEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TachyonEvent::init_info()
    {
        auto w = writer<TachyonEvent>();
        w.description("Tachyon event base class");
    }
    
    YQ_INVOKE(TachyonEvent::init_info();)
}
