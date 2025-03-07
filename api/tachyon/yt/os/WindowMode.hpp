////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    enum class WindowMode {
        //! Normal mode
        Normal      = 0,
        
        //! Minimized/Iconified
        Iconified,
        
        //! Maximized
        Maximized,
        
        //! "Window" full screen (no decorations)
        Windowed,
        
        //! Full screen (no decorations, full video mode)
        Fullscreen
    };
}
