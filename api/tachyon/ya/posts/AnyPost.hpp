////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Any.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {

    /*! \brief Test post, carries an any value
    */
    class AnyPost : public Post {
        YQ_OBJECT_DECLARE(AnyPost, Post)
    public:
    
        AnyPost(const Any& val, const Header&h={});
        AnyPost(Any&& val, const Header&h={});
    
        const Any&    value() const { return m_value; }
        
        static void init_info();
    
    protected:
        ~AnyPost();
        
        AnyPost(const AnyPost&, const Header&);
    
    private:
        Any     m_value;
        
        AnyPost(const AnyPost&) = delete;
        AnyPost(AnyPost&&) = delete;
        AnyPost& operator=(const AnyPost&) = delete;
        AnyPost& operator=(AnyPost&&) = delete;
    };
}
