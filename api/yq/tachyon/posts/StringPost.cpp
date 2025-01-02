////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "StringPost.hpp"
#include <yt/PostInfoWriter.hpp>

namespace yq::tachyon {
    StringPost::StringPost(std::string&&k, const Param&p) : Post(p), m_text(std::move(k))
    {
    }
    
    StringPost::StringPost(const char* k, const Param&p) : Post(p), m_text(k)
    {
    }
    
    StringPost::StringPost(std::string_view k, const Param&p) : Post(p), m_text(k)
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
