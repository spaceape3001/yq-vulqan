////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Any.hpp>
#include <yt/msg/Reply.hpp>

namespace yq::tachyon {

    /*! \brief Test post, carries an any value
    */
    class AnyReply : public Reply {
        YQ_OBJECT_DECLARE(AnyReply, Reply)
    public:
    
        using Reply::Param;
        
        AnyReply(const RequestCPtr&, const Any& val, const Param&p={});
        AnyReply(const RequestCPtr&, Any&& val, const Param&p={});
        ~AnyReply();
    
        const Any&    value() const { return m_value; }
    
        static void init_info();
    
    private:
        Any     m_value;
    };
}
