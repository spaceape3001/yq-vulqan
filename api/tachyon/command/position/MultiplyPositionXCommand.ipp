////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionˣCommand)

namespace yq::tachyon {
    MultiplyPositionˣCommand::MultiplyPositionˣCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MultiplyPositionˣCommand::MultiplyPositionˣCommand(const Header&h, double x) : 
        PositionCommand(h), m_δx(x)
    {
    }

    MultiplyPositionˣCommand::MultiplyPositionˣCommand(const MultiplyPositionˣCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyPositionˣCommand::~MultiplyPositionˣCommand()
    {
    }
    
    PostCPtr    MultiplyPositionˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionˣCommand(*this, h);
    }

    void MultiplyPositionˣCommand::init_meta()
    {
        auto w = writer<MultiplyPositionˣCommand>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPositionˣCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
