////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Event.hpp"
#include "EventFilter.hpp"
#include "EventProducer.hpp"
#include "EventSocket.hpp"

namespace yq::tachyon {
    EventSocket::EventSocket()
    {
    }
    
    EventSocket::~EventSocket()
    {
        unsubscribe_all();
    }

    bool    EventSocket::_has(EventProducer*prod) const
    {
        for(EventProducer* e : m_producers){
            if(e == prod)
                return true;
        }
        return false;
    }
    
    void    EventSocket::_subscribe(EventProducer*prod)
    {
        if(_has(prod))
            return;
        m_producers.push_back(prod);
    }
    

    void    EventSocket::_unsubscribe(EventProducer* prod)
    {
        std::erase(m_producers, prod);
    }

    std::string_view    EventSocket::description() const
    {
        if(const Object* obj = dynamic_cast<const Object*>(this)){
            return obj -> metaInfo().description();
        }
        
        return "Generic Event Socket";
    }

    std::string_view    EventSocket::name() const
    {
        if(const Object* obj = dynamic_cast<const Object*>(this)){
            return obj -> metaInfo().name();
        }
        
        return "EventSocket";
    }
    
    void    EventSocket::subscribe(EventProducer&prod)
    {
        _subscribe(&prod);
        prod._subscribe(this);
    }
    
    void    EventSocket::unsubscribe(EventProducer&prod)
    {
        _unsubscribe(&prod);
        prod._unsubscribe(this);
    }
    
    void    EventSocket::unsubscribe_all()
    {
        for(EventProducer* prod : m_producers){
            prod -> _unsubscribe(this);
        }
        m_producers.clear();
    }
}
