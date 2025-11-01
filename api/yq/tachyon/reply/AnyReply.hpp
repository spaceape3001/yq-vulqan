////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Any.hpp>
#include <yq/tachyon/api/Reply.hpp>

namespace yq::tachyon {

    /*! \brief Test post, carries an any value
    */
    class AnyReply : public Reply {
        YQ_OBJECT_DECLARE(AnyReply, Reply)
    public:
    
        AnyReply(const Header&, const RequestCPtr&, const Any& val);
        AnyReply(const Header&, const RequestCPtr&, Any&& val);
        const Any&    value() const { return m_value; }
    
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        
        AnyReply(const AnyReply&, const Header&);
        virtual ~AnyReply();
    
    private:
        Any     m_value;
        
        AnyReply(const AnyReply&) = delete;
        AnyReply(AnyReply&&) = delete;
        AnyReply& operator=(const AnyReply&) = delete;
        AnyReply& operator=(AnyReply&&) = delete;
    };
}
