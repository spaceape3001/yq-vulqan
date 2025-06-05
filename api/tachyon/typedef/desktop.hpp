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
    class Desktop;
    using DesktopPtr      = Ref<Desktop>;
    using DesktopCPtr     = Ref<const Desktop>;

    struct DesktopSnap;
    using DesktopSnapPtr  = Ref<DesktopSnap>;
    using DesktopSnapCPtr = Ref<const DesktopSnap>;
    
    struct DesktopData;
    using DesktopDataPtr  = Ref<DesktopData>;
    using DesktopDataCPtr = Ref<const DesktopData>;

    template <class> class ID;
    using DesktopID = ID<Desktop>;
    
    class DesktopInfo;
}
