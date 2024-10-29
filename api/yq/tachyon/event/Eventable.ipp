////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Event.hpp"
#include "EventProducer.hpp"
#include "EventProducerThread.hpp"
#include "EventSocket.hpp"

namespace yq::tachyon {
    EventProducer::Thread&      EventProducer::thread()
    {
        static thread_local Thread  s_ret;
        return s_ret;
    }

    EventProducer::EventProducer()
    {
    }
    
    EventProducer::~EventProducer()
    {
        unsubscribe_all();
    }

    bool    EventProducer::_has(EventSocket*sock) const
    {
        for(EventSocket* s : m_sockets){
            if(s == sock)
                return true;
        }
        return false;
    }

    void    EventProducer::_subscribe(EventSocket* sock)
    {
        if(_has(sock))
            return;
        m_sockets.push_back(sock);
    }
    
    void    EventProducer::_unsubscribe(EventSocket* sock)
    {
        std::erase(m_sockets, sock);
    }

    std::string_view    EventProducer::description() const
    {
        if(const Object* obj = dynamic_cast<const Object*>(this)){
            return obj -> metaInfo().description();
        }
        
        return "Generic Event Producer";
    }

    uint64_t    EventProducer::events_generated() const 
    { 
        return m_count; 
    }


    std::string_view    EventProducer::name() const
    {
        if(const Object* obj = dynamic_cast<const Object*>(this)){
            return obj -> metaInfo().name();
        }
        
        return "EventProducer";
    }

    void  EventProducer::publish(EventPtr evt)
    {
        if(!evt)
            return ;
        ++m_count;
        if(!evt->m_originator)
            evt -> m_originator    = this;
        auto& t = thread();
        if(t.socket)
            t.socket->handle(*evt);
        for(EventSocket* s : m_sockets)
            s -> handle(*evt);
    }

    void  EventProducer::subscribe(rx_t, EventSocket& sock)
    {
        _subscribe(&sock);
        sock._subscribe(this);
    }
    
    void  EventProducer::unsubscribe(EventSocket&sock)
    {
        _unsubscribe(&sock);
        sock._unsubscribe(this);
    }
    
    void  EventProducer::unsubscribe_all()
    {
        for(EventSocket* s : m_sockets){
            s->_unsubscribe(this);
        }
        m_sockets.clear();
    }

}
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
