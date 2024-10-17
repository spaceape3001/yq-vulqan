////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Event.hpp"
#include "EventManager.hpp"
#include "EventProducerThread.hpp"
#include "EventSocket.hpp"

#include <tachyon/app/ManagerInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void EventManager::init_info()
    {
        auto w = writer<EventManager>();
        w.description("Abstract event manager base class");
    }

    EventManager::EventManager()
    {
    }
    
    EventManager::~EventManager()
    {
    }
    
    void                EventManager::_poll(EventSocket*sock, unit::Second timeout)
    {
        if(m_polling.test_and_set())
            return ;
    
        auto& t = thread();
        EventSocket*    old = t.socket;
        t.socket        = sock;
        _poll(timeout);
        t.socket        = old;
        
        m_polling.clear();
    }

    std::string_view    EventManager::description() const
    {
        for(const Meta* m = &metaInfo(); m; m = m -> parent()){
            std::string_view d = m->description();
            if(!d.empty())
                return d;
        }
        return {};
    }

    std::string_view    EventManager::name() const
    {
        return metaInfo().name();
    }

    void  EventManager::poll(Second dur)
    {
        _poll(nullptr, dur);
    }
    
    void  EventManager::poll(EventSocket&sock, Second dur)
    {
        _poll(&sock, dur);
    }

    YQ_INVOKE(EventManager::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EventManager)

