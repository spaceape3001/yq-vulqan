////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/posts/EmptyPost.hpp>
#include <yt/msg/PostInfoWriter.hpp>

namespace yq::tachyon {
    EmptyPost::EmptyPost(const Header&h) : Post(h) 
    {
    }
    
    EmptyPost::~EmptyPost()
    {
    }

    EmptyPost::EmptyPost(const EmptyPost&cp, const Header&h) : Post(cp, h) 
    {
    }
    
    void EmptyPost::init_info()
    {
        auto w = writer<EmptyPost>();
        w.description("Empty Post");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyPost)
