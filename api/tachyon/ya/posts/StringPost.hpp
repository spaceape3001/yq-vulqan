////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Post.hpp>
#include <string>
#include <string_view>

namespace yq::tachyon {

    //! Test post type that carries a string 
    class StringPost : public Post {
        YQ_OBJECT_DECLARE(StringPost, Post)
    public:
    
        StringPost(std::string&&, const Header&h={});
        StringPost(const char*, const Header&h={});
        StringPost(std::string_view, const Header&h={});
    
        const std::string&    text() const { return m_text; }
        
        static void init_info();
    
    protected:
        StringPost(const StringPost&, const Header&);
        ~StringPost();
    
    private:
        std::string     m_text;
    };
}
