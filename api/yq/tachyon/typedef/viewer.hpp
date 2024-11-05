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
    
    using ViewerCreateInfoUPtr  = std::unique_ptr<struct ViewerCreateInfo>;
}
