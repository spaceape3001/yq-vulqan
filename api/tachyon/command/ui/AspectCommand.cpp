////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/AspectCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AspectCommand)

namespace yq::tachyon {

    AspectCommand::AspectCommand(const Header&h, const Size2I& _aspect) : UICommand(h), m_aspect(_aspect)
    {
    }

    AspectCommand::AspectCommand(const AspectCommand& cp, const Header& h) : UICommand(cp, h), m_aspect(cp.m_aspect)
    {
    }
    
    AspectCommand::~AspectCommand()
    {
    }

    PostCPtr    AspectCommand::clone(rebind_k, const Header&h) const 
    {
        return new AspectCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AspectCommand::init_info()
    {
        auto w = writer<AspectCommand>();
        w.description("Aspect Command");
        w.property("aspect", &AspectCommand::aspect).description("Aspect ratio").tag(kTag_Save);
        w.property("w", &AspectCommand::width).description("Aspect width").tag(kTag_Log);
        w.property("h", &AspectCommand::height).description("Aspect height").tag(kTag_Log);
    }
}
