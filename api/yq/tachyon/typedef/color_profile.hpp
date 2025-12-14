////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq { template <typename> class Ref; }

namespace yq::tachyon {
    class Texture;
    using ColorProfile = Texture;
    //class ColorProfile;
    using ColorProfilePtr   = Ref<ColorProfile>;
    using ColorProfileCPtr  = Ref<const ColorProfile>;
}
