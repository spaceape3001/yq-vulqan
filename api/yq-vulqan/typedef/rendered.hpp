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
    class Rendered;
    using RenderedPtr       = Ref<Rendered>;
    using RenderedCPtr      = Ref<const Rendered>;
    
    class ViRendered;
    using ViRenderedPtr     = Ref<ViRendered>;
    using ViRenderedCPtr    = Ref<const ViRendered>;
    
    struct ViRenderedOptions;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViRenderedManager = ViManager<ViRendered, RenderedCPtr, ViRenderedOptions>;
    using ViRenderedManagerUPtr = std::unique_ptr<ViRenderedManager>;
    using ViRenderedManagerSPtr = std::shared_ptr<ViRenderedManager>;
}
