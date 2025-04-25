////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Frame.hpp"

namespace yq::tachyon {

    struct Frame::Builder {
    
        Builder(Frame&);
        ~Builder();
        
        void        add(ThreadID, const ThreadData&);
        void        finalize();
        
    private:
        Frame&                                          m_frame;
        std::vector<std::pair<ThreadID, TachyonFrame>>  m_pushed;
    };
}
