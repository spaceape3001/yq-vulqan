////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq::tachyon {
    class Rendered;
    class ViRendered;
    
    struct ViRenderedOptions;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViRenderedManager = ViManager<ViRendered, RenderedCPtr, ViRenderedOptions>;
    using ViRenderedManagerUPtr = std::unique_ptr<ViRenderedManager>;
    using ViRenderedManagerSPtr = std::shared_ptr<ViRenderedManager>;
}
