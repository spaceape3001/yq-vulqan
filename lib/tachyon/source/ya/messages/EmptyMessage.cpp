////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/messages/EmptyMessage.hpp>
#include <yt/msg/MessageInfoWriter.hpp>

namespace yq::tachyon {
    EmptyMessage::EmptyMessage(const Param& p) : Message(p) 
    {
    }
    
    EmptyMessage::~EmptyMessage()
    {
    }
    
    void EmptyMessage::init_info()
    {
        auto w = writer<EmptyMessage>();
        w.description("Empty Message");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyMessage)
