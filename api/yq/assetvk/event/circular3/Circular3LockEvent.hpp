////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/event/Circular3Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³LockEvent : public Circular³Event {
        YQ_OBJECT_DECLARE(Circular³LockEvent, Circular³Event)
    public:
    
        static void init_meta();
        Circular³LockEvent(const Header&, bool);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        bool    lock() const { return m_lock; }
        
    protected:
        Circular³LockEvent(const Circular³LockEvent&, const Header&);
        ~Circular³LockEvent();
        
    private:
        bool    m_lock;
    
        Circular³LockEvent(const Circular³LockEvent&) = delete;
        Circular³LockEvent(Circular³LockEvent&&) = delete;
        Circular³LockEvent& operator=(const Circular³LockEvent&) = delete;
        Circular³LockEvent& operator=(Circular³LockEvent&&) = delete;
    };
}
