////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/thread.hpp>

namespace yq::tachyon {
    /*
        DO NOT DECLARE THREAD ID with the ID class... different IDs.
    */

    //! Utiltity to bind a thread to the whatever...
    class ThreadBind {
    public:
        ThreadID thread() const { return m_thread; }
        
    protected:
        ThreadBind(ThreadID v) : m_thread(v) {}
        ThreadBind(const Thread*);
        virtual ~ThreadBind(){}
        ThreadID const   m_thread;
    };
}
