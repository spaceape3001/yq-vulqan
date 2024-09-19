////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/frame_thread.hpp>
#include <yq-vulqan/viz/ViCommandPool.hpp>

namespace yq::tachyon {

    class ViFrameThread {
    public:
    
    private:
        ViVisualizer*       m_viz   = nullptr;
        ViCommandPool       m_commandPool;
    };
}
