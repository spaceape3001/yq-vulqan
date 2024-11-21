////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Frame.hpp"

namespace yq::tachyon {

    struct Frame::Builder {
    
        Builder(ThreadID);
        ~Builder();
        
        void        add(ThreadID, const ThreadData&);
        FramePtr    finalize();
        
    private:
        FramePtr                                        m_frame;
        std::vector<std::pair<ThreadID, TachyonFrame>>  m_pushed;
    };
}
