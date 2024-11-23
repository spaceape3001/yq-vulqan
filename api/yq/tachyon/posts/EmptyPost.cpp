////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EmptyPost.hpp"
#include <yq/tachyon/api/PostInfoWriter.hpp>

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
