////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Post.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyPost : public Post {
        YQ_OBJECT_DECLARE(EmptyPost, Post)
    public:
        
        EmptyPost(const Param&p={});
        ~EmptyPost();
        
        static void init_info();
    };
}
