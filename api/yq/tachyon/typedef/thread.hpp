////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class Thread;
    
    /*
        DO NOT DECLARE THREAD ID with the ID class... different IDs.
    */

    //! Utiltity to bind a thread to the whatever...
    class ThreadBind {
    public:
        Thread* thread() const { return m_thread; }
        
    protected:
        ThreadBind(Thread* v) : m_thread(v) {}
        virtual ~ThreadBind(){}
        Thread* const   m_thread;
    };
}
