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
    template <class> class ID;

    class Post;
    class PostInfo;
    using PostPtr           = Ref<Post>;
    using PostCPtr          = Ref<const Post>;
    
    using PostID            = ID<Post>;

    template <class P>
    concept SomePost        = std::derived_from<P,Post>;
    
    template <SomePost P>
    struct post_k {
        using ThePost = P;
    };
    
    template <SomePost P=Post>
    static constexpr const post_k<P>    POST;
}
