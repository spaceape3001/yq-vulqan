////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Post.hpp>
#include <string>
#include <string_view>

namespace yq::tachyon {

    //! Test post type that carries a string 
    class StringPost : public Post {
        YQ_OBJECT_DECLARE(StringPost, Post)
    public:
    
        StringPost(std::string&&, const Param&p={});
        StringPost(const char*, const Param&p={});
        StringPost(std::string_view, const Param&p={});
        ~StringPost(){}
    
        const std::string&    text() const { return m_text; }
        
        static void init_info();
    
    private:
        std::string     m_text;
    };
}
