////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/event.hpp>
#include <string_view>
#include <vector>
//#include <tbb/spin_rw_mutex.h> // if we need it

namespace yq::tachyon {
    /*! \brief Receiver of events
    
        This is what takes in events
    */
    class EventSocket {
    public:
        virtual void                handle(EventPtr) = 0;
        virtual std::string_view    description() const;
        virtual std::string_view    name() const;
        
        void    subscribe(EventProducer&);
        void    unsubscribe(EventProducer&);
        void    unsubscribe_all();
        
    protected:
        EventSocket();
        ~EventSocket();
    private:
        friend class EventProducer;
    
        bool    _has(EventProducer*) const;
        void    _subscribe(EventProducer*);
        void    _unsubscribe(EventProducer*);
    
        //mutable tbb::spin_rw_mutex  m_mutex;
        std::vector<EventProducer*> m_producers;
    };
}
