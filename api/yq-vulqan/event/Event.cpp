////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Event.hpp"
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Event)

namespace yq::tachyon {
    
    EventInfo::EventInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::EVENT);
    }

    ////////////////////////////////////////////////////////////////////////////

    Event::Event()
    {
    }
    
    Event::~Event()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_event()
    {
        {
            auto w = writer<Event>();
            w.description("Event base class");
        }
    }
    
    YQ_INVOKE(reg_event();)
}
