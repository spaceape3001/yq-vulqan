////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/tachyon/DestroyCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DestroyCommand)

namespace yq::tachyon {

    DestroyCommand::DestroyCommand(const Header&h) : TachyonCommand(h)
    {
    }

    DestroyCommand::DestroyCommand(const DestroyCommand& cp, const Header& h) : TachyonCommand(cp, h)
    {
    }
    
    DestroyCommand::~DestroyCommand()
    {
    }

    PostCPtr    DestroyCommand::clone(rebind_k, const Header&h) const 
    {
        return new DestroyCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void DestroyCommand::init_info()
    {
        auto w = writer<DestroyCommand>();
        w.description("Destroy Command");
    }
}
