////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Event.hpp"
#include "EventInfoWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Event)

namespace yq::tachyon {
    EventInfo::EventInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
    {
        set(Flag::EVENT);
    }

    ////////////////////////////////////////////////////////////////////////////

    Event::Event(const Param&p) : Post(p)
    {
    }
    
    Event::~Event()
    {
    }


    ////////////////////////////////////////////////////////////////////////////

    void Event::init_info()
    {
        auto w = writer<Event>();
        w.description("Abstract Event Class");
    }
}
