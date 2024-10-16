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

        void    subscribe(EventSocket&);
        void    unsubscribe(EventSocket&);
        void    unsubscribe_all();

        virtual std::string_view    name() const;
        virtual std::string_view    description() const;

    protected:

        void                    publish(EventPtr);

        EventProducer();
        ~EventProducer();
    
    private:
        
        friend class EventSocket;
        friend class EventManager;

        struct Thread;
        static Thread&              thread();

        //mutable tbb::spin_rw_mutex  m_mutex;
        std::vector<EventSocket*>   m_sockets;
        
        bool    _has(EventSocket*) const;
        void    _subscribe(EventSocket*);
        void    _unsubscribe(EventSocket*);
    };
}
