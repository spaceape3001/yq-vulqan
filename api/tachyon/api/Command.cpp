////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Command)

namespace yq::tachyon {
    CommandMeta::CommandMeta(std::string_view zName, PostMeta& base, const std::source_location& sl) :
        PostMeta(zName, base, sl)
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

    void Command::init_meta()
    {
        auto w = writer<Command>();
        w.description("Abstract Command Class");
    }
}
