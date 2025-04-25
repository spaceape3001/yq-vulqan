////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Message.hpp>
#include <tachyon/api/MessageInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Message)

namespace yq::tachyon {
    MessageInfo::MessageInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
    {
        set(Flag::MESSAGE);
    }

    ////////////////////////////////////////////////////////////////////////////

    Message::Message(const Param&) : Post({})
    {
        // DEPRECATED
    }

    Message::Message(const Header&h) : Post(h)
    {
    }

    Message::Message(const Message& cp, const Header&h) : Post(cp, h)
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
