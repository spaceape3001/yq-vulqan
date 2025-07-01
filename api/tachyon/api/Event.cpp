////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Event.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Event)

namespace yq::tachyon {
    EventMeta::EventMeta(std::string_view zName, PostMeta& base, const std::source_location& sl) :
        PostMeta(zName, base, sl)
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
