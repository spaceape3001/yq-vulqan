////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonCommand.hpp"

#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonCommand)

namespace yq::tachyon {
    TachyonCommandInfo::TachyonCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl) :
        post::CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    TachyonCommand::TachyonCommand(Tachyon* v, const Param& p) : post::Command(p), TachyonBind(v)
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
