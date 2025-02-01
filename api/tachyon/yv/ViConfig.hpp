////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

struct GLFWwindow;

namespace yq {
    class Cleanup;
}

namespace yq::tachyon {

    struct ViewerCreateInfo;
    
    struct ViConfig {
        const ViewerCreateInfo&     viewer;
        GLFWwindow*                 window;
        Cleanup&                    cleanup;
    };
}
