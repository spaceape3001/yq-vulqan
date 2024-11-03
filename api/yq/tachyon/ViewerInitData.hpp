////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ViewerState.hpp>

struct GLFWwindow;

namespace yq::tachyon {

    //  This is meant to be initialization for the viewer...
    struct ViewerInitData {
        GLFWwindow*     window  = nullptr;
        ViewerState     state;
    };
}

