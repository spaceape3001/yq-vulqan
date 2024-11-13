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
    class Post;
    class PostInfo;
    using PostPtr           = Ref<Post>;
    using PostCPtr          = Ref<const Post>;

    template <class P>
    concept SomePost        = std::derived_from<P,Post>;
}
