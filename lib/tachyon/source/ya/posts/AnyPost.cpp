////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/posts/AnyPost.hpp>
#include <yt/msg/PostInfoWriter.hpp>

namespace yq::tachyon {
    AnyPost::AnyPost(const Any& val, const Param&p) : Post(p), m_value(val)
    {
    }
    
    AnyPost::AnyPost(Any&& val, const Param&p) : Post(p), m_value(std::move(val))
    {
    }
    
    AnyPost::~AnyPost()
    {
    }

    void AnyPost::init_info()
    {
        auto w = writer<AnyPost>();
        w.description("Any Post");
        w.property("value", &AnyPost::value);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::AnyPost)
