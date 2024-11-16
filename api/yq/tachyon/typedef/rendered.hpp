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

    template <class> class ID;
    
    using RenderedID = ID<Rendered>;
}
