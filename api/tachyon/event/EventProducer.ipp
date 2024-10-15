////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Event.hpp"
#include "EventProducer.hpp"
#include "EventSocket.hpp"

namespace yq::tachyon {
    struct EventProducer::Thread {
        EventSocket*    socket  = nullptr;
    };

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

    void    EventProducer::_poll(EventSocket* sock)
    {
        auto& t = thread();
        EventSocket*    old = t.socket;
        t.socket        = sock;
        poll_events();
        t.socket        = old;
    }
    
    void    EventProducer::_push(EventPtr&& ev)
    {
        auto& t = thread();
        if(t.socket){
            t.socket->handle(ev);
        }
        for(EventSocket* s : m_sockets)
            s -> handle(ev);
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

    std::string_view    EventProducer::name() const
    {
        if(const Object* obj = dynamic_cast<const Object*>(this)){
            return obj -> metaInfo().name();
        }
        
        return "EventProducer";
    }

    void  EventProducer::poll()
    {
        _poll(nullptr);
    }
    
    void  EventProducer::poll(EventSocket&sock)
    {
        _poll(&sock);
    }

    void  EventProducer::publish(EventPtr ep, bool keepExisting)
    {
        if(ep){
            if(!(keepExisting && ep->m_producer)){
                ep -> m_producer    = this;
            }
            _push(std::move(ep));
        }
    }

    void  EventProducer::subscribe(EventSocket& sock)
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
