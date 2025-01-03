////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/posts/EmptyPost.hpp>
#include <yt/msg/PostInfoWriter.hpp>

namespace yq::tachyon {
    EmptyPost::EmptyPost(const Param&p) : Post(p) 
    {
    }
    
    EmptyPost::~EmptyPost()
    {
    }
    
    void EmptyPost::init_info()
    {
        auto w = writer<EmptyPost>();
        w.description("Empty Post");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyPost)
