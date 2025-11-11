////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/post/AnyPost.hpp>
#include <yq/tachyon/api/PostMetaWriter.hpp>

namespace yq::tachyon {
    AnyPost::AnyPost(const Any& val, const Header&h) : Post(h), m_value(val)
    {
    }
    
    AnyPost::AnyPost(Any&& val, const Header&h) : Post(h), m_value(std::move(val))
    {
    }
    
    AnyPost::AnyPost(const AnyPost&cp, const Header&h) : Post(cp, h), m_value(cp.m_value)
    {
    }

    AnyPost::~AnyPost()
    {
    }

    void AnyPost::init_meta()
    {
        auto w = writer<AnyPost>();
        w.description("Any Post");
        w.property("value", &AnyPost::value);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::AnyPost)
