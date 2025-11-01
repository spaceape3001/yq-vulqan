////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyPost : public Post {
        YQ_OBJECT_DECLARE(EmptyPost, Post)
    public:
        
        EmptyPost(const Header&p={});
        ~EmptyPost();
        
        static void init_meta();
    
    protected:
        EmptyPost(const EmptyPost&, const Header&);
        
    private:
        EmptyPost(const EmptyPost&) = delete;
        EmptyPost(EmptyPost&&) = delete;
        EmptyPost& operator=(const EmptyPost&) = delete;
        EmptyPost& operator=(EmptyPost&&) = delete;
    };
}
