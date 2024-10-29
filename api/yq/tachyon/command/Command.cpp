////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Command.hpp"

#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Command)

namespace yq::tachyon {
    
    CommandInfo::CommandInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::COMMAND);
    }

    ////////////////////////////////////////////////////////////////////////////

    Command::Command()
    {
    }
    
    Command::~Command()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_command()
    {
        {
            auto w = writer<Command>();
            w.description("Command base class");
        }
    }
    
    YQ_INVOKE(reg_command();)
}
