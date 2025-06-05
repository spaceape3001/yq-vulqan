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
    class Rendered;
    using RenderedPtr       = Ref<Rendered>;
    using RenderedCPtr      = Ref<const Rendered>;

    struct RenderedSnap;
    using RenderedSnapPtr  = Ref<RenderedSnap>;
    using RenderedSnapCPtr = Ref<const RenderedSnap>;
    
    struct RenderedData;
    using RenderedDataPtr  = Ref<RenderedData>;
    using RenderedDataCPtr = Ref<const RenderedData>;

    template <class> class ID;
    
    using RenderedID = ID<Rendered>;
    class RenderedInfo;
}
