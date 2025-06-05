////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Window;
    using WindowPtr      = Ref<Window>;
    using WindowCPtr     = Ref<const Window>;

    struct WindowSnap;
    using WindowSnapPtr  = Ref<WindowSnap>;
    using WindowSnapCPtr = Ref<const WindowSnap>;
    
    struct WindowData;
    using WindowDataPtr  = Ref<WindowData>;
    using WindowDataCPtr = Ref<const WindowData>;

    template <class> class ID;
    using WindowID = ID<Window>;
    
    class WindowInfo;
}
