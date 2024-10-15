////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/event.hpp>
#include <vector>
//#include <tbb/spin_rw_mutex.h> // if we need it

namespace yq::tachyon {
    class EventProducer {
    public:

        //! Polls to events, publishing to all
        void    poll();
        
        //! Polls to events, publishing to all *AND* the provided socket (first)
        void    poll(EventSocket&);
        void    subscribe(EventSocket&);
        void    unsubscribe(EventSocket&);
        void    unsubscribe_all();

        virtual std::string_view    name() const;
        virtual std::string_view    description() const;
        
    protected:
        void                    publish(EventPtr, bool keepExisting=false);
        virtual void            poll_events() = 0;

        EventProducer();
        ~EventProducer();
    
    private:
        struct Thread;
        static Thread&              thread();
        
        friend class EventSocket;

        //mutable tbb::spin_rw_mutex  m_mutex;
        std::vector<EventSocket*>   m_sockets;
        
        bool    _has(EventSocket*) const;
        void    _poll(EventSocket*);
        void    _push(EventPtr&&);
        void    _subscribe(EventSocket*);
        void    _unsubscribe(EventSocket*);
    };
}
