////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>

namespace yq { 
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Request;
    class RequestMeta;
    using RequestPtr    = Ref<Request>;
    using RequestCPtr   = Ref<const Request>;

    template <class Q>
    concept SomeRequest = std::derived_from<Q,Request>;
}
