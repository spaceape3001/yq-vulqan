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
    class Reply;
    class ReplyMeta;
    using ReplyPtr           = Ref<Reply>;
    using ReplyCPtr          = Ref<const Reply>;

    template <class R>
    concept SomeReply        = std::derived_from<R,Reply>;
}
