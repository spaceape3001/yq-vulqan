////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Event.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Event)

namespace yq::tachyon {
    EventInfo::EventInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
    {
        set(Flag::EVENT);
    }

    ////////////////////////////////////////////////////////////////////////////

    Event::Event(const Param&) : Post({})
    {
        // DEPRECATED
    }

    Event::Event(const Header& h) : Post(h) 
    {
    }

    Event::Event(const Event&cp, const Header&h) : Post(cp, h)
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
