////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Viewer;
    using ViewerPtr         = Ref<Viewer>;
    using ViewerCPtr        = Ref<const Viewer>;

    struct ViewerSnap;
    using ViewerSnapPtr  = Ref<ViewerSnap>;
    using ViewerSnapCPtr = Ref<const ViewerSnap>;
    
    struct ViewerData;
    using ViewerDataPtr  = Ref<ViewerData>;
    using ViewerDataCPtr = Ref<const ViewerData>;

    template <class> class ID;
    using ViewerID = ID<Viewer>;
    
    using ViewerCreateInfoUPtr  = std::unique_ptr<struct ViewerCreateInfo>;
}
