////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Event.hpp"
#include "EventInfoWriter.hpp"
#include "EventProducer.hpp"
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

    bool    Event::_dispatch()
    {
        return false;
    }

    void Event::dispatch()
    {
        if(mark()){
            if(!_dispatch()){
                m_handled.clear();
            }
        }
    }

    bool Event::handled() const
    {
        return m_handled.test();
    }

    bool Event::mark()
    {
        return !m_handled.test_and_set();
    }

    void Event::reset()
    {
        m_handled.clear();
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
