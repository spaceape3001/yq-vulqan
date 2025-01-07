////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/posts/StringPost.hpp>
#include <yt/msg/PostInfoWriter.hpp>

namespace yq::tachyon {
    StringPost::StringPost(std::string&&k, const Header&h) : Post(h), m_text(std::move(k))
    {
    }
    
    StringPost::StringPost(const char* k, const Header&h) : Post(h), m_text(k)
    {
    }
    
    StringPost::StringPost(std::string_view k, const Header&h) : Post(h), m_text(k)
    {
    }
    
    StringPost::StringPost(const StringPost&cp, const Header& h) : Post(h), m_text(cp.m_text)
    {
    }
    
    StringPost::~StringPost()
    {
    }

    void StringPost::init_info()
    {
        auto w = writer<StringPost>();
        w.description("Text Post");
        w.property("text", &StringPost::text);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::StringPost)
