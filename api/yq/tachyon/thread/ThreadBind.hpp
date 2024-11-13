////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class Thread;

    //! Utiltity to bind a viewer to the whatever...
    class ThreadBind {
    public:
        Thread* thread() const { return m_thread; }
        
    protected:
        ThreadBind(Thread* v) : m_thread(v) {}
        virtual ~ThreadBind(){}
        Thread* const   m_thread;
    };
}
