////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstddef>
#include <cstdint>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Pixmap;
    using PixmapPtr     = Ref<Pixmap>;
    using PixmapCPtr    = Ref<const Pixmap>;
    
    class Pixmap2;
    using Pixmap2Ptr    = Ref<Pixmap2>;
    using Pixmap2CPtr   = Ref<const Pixmap2>;

    template <typename C, typename I=size_t> class Pixmap2C;
}
