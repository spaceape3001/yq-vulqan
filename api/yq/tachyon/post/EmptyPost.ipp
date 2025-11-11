////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/post/EmptyPost.hpp>
#include <yq/tachyon/api/PostMetaWriter.hpp>

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
    
    void EmptyPost::init_meta()
    {
        auto w = writer<EmptyPost>();
        w.description("Empty Post");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyPost)
