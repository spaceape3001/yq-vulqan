////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonCommand.hpp"

#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonCommand)

namespace yq::tachyon {
    TachyonCommandInfo::TachyonCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    TachyonCommand::TachyonCommand(TachyonID v, const Param& p) : Command(p), TachyonBind(v)
    {
    }
    
    TachyonCommand::TachyonCommand(Tachyon* v, const Param& p) : Command(p), TachyonBind(v)
    {
    }

    TachyonCommand::~TachyonCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TachyonCommand::init_info()
    {
        auto w = writer<TachyonCommand>();
        w.description("Tachyon command base class");
    }
}
