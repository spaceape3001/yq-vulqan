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
    class GraphicsCard;
    using GraphicsCardPtr      = Ref<GraphicsCard>;
    using GraphicsCardCPtr     = Ref<const GraphicsCard>;

    struct GraphicsCardSnap;
    using GraphicsCardSnapPtr  = Ref<GraphicsCardSnap>;
    using GraphicsCardSnapCPtr = Ref<const GraphicsCardSnap>;
    
    struct GraphicsCardData;
    using GraphicsCardDataPtr  = Ref<GraphicsCardData>;
    using GraphicsCardDataCPtr = Ref<const GraphicsCardData>;

    template <class> class ID;
    using GraphicsCardID = ID<GraphicsCard>;
    class GraphicsCardMeta;
}
