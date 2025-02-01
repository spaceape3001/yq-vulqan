////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/msg/Command.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Command)

namespace yq::tachyon {
    CommandInfo::CommandInfo(std::string_view zName, PostInfo& base, const std::source_location& sl) :
        PostInfo(zName, base, sl)
    {
        set(Flag::COMMAND);
    }

    ////////////////////////////////////////////////////////////////////////////

    Command::Command(const Param&) : Post({}) 
    {
        // DEPRECATED
    }

    Command::Command(const Header& h) : Post(h)
    {
    }

    Command::Command(const Command& cp, const Header& h) : Post(cp, h)
    {
    }
    
    Command::~Command()
    {
    }


    ////////////////////////////////////////////////////////////////////////////

    void Command::init_info()
    {
        auto w = writer<Command>();
        w.description("Abstract Command Class");
    }
}
