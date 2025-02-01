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
}
