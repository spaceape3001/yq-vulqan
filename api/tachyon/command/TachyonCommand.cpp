////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/TachyonCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonCommand)

namespace yq::tachyon {
    TachyonCommand::TachyonCommand(const Header& h) : Command(h)
    {
    }
    
    TachyonCommand::TachyonCommand(const TachyonCommand& cp, const Header& h) : Command(cp, h)
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
