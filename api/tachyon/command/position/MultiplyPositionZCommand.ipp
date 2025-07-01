////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionᶻCommand)

namespace yq::tachyon {
    MultiplyPositionᶻCommand::MultiplyPositionᶻCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MultiplyPositionᶻCommand::MultiplyPositionᶻCommand(const Header&h, double z) : 
        PositionCommand(h), m_δz(z)
    {
    }
    
    MultiplyPositionᶻCommand::MultiplyPositionᶻCommand(const MultiplyPositionᶻCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyPositionᶻCommand::~MultiplyPositionᶻCommand()
    {
    }

    PostCPtr    MultiplyPositionᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionᶻCommand(*this, h);
    }
    
    void MultiplyPositionᶻCommand::init_meta()
    {
        auto w = writer<MultiplyPositionᶻCommand>();
        w.description("Multiply Position Command");
        w.property("δz", &MultiplyPositionᶻCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
