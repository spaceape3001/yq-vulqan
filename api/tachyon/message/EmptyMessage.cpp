////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/message/EmptyMessage.hpp>
#include <tachyon/api/MessageMetaWriter.hpp>

namespace yq::tachyon {
    EmptyMessage::EmptyMessage(const Param& p) : Message(p) 
    {
    }
    
    EmptyMessage::~EmptyMessage()
    {
    }
    
    void EmptyMessage::init_meta()
    {
        auto w = writer<EmptyMessage>();
        w.description("Empty Message");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyMessage)
