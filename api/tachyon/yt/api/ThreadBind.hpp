////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    /*
        DO NOT DECLARE THREAD ID with the ID class... different IDs.
    */
    struct TypedID;

    //! Utiltity to bind a thread to the whatever...
    class ThreadBind {
    public:
        ThreadID thread() const { return m_thread; }
        
    protected:
        constexpr ThreadBind(ThreadID v) noexcept : m_thread(v) {}
        ThreadBind(const Thread*);
        ThreadBind(TypedID);
        virtual ~ThreadBind(){}
        ThreadID const   m_thread;
    };
}
