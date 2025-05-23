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
    class ViShader;
    using ViShaderPtr           = Ref<ViShader>;
    using ViShaderCPtr          = Ref<const ViShader>;
}
