////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Reply.hpp>
#include <string>
#include <string_view>

namespace yq::tachyon {

    //! Test post type that carries a string 
    class StringReply : public Reply {
        YQ_OBJECT_DECLARE(StringReply, Reply)
    public:
        
        StringReply(const Header&, const RequestCPtr&, std::string_view);
        const std::string&    text() const { return m_text; }
        static void init_info();

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        StringReply(const StringReply&, const Header&);
        ~StringReply();
    
    private:
        std::string     m_text;
        
        StringReply(const StringReply&) = delete;
        StringReply(StringReply&&) = delete;
        StringReply& operator=(const StringReply&) = delete;
        StringReply& operator=(StringReply&&) = delete;
    };
}
