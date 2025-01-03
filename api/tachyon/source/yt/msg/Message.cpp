////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/msg/Message.hpp>
#include <yt/msg/MessageInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Message)

namespace yq::tachyon {
    MessageInfo::MessageInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
    {
        set(Flag::MESSAGE);
    }

    ////////////////////////////////////////////////////////////////////////////

    Message::Message(const Param& p) : Post(p)
    {
    }
    
    Message::~Message()
    {
    }


    ////////////////////////////////////////////////////////////////////////////

    void Message::init_info()
    {
        auto w = writer<Message>();
        w.description("Abstract Message Class");
    }
}
