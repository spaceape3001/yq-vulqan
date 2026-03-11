////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPositionZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionᶻDCommand)

namespace yq::tachyon {
    MultiplyPositionᶻDCommand::MultiplyPositionᶻDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MultiplyPositionᶻDCommand::MultiplyPositionᶻDCommand(const Header&h, double z) : 
        PositionCommand(h), m_δz(z)
    {
    }
    
    MultiplyPositionᶻDCommand::MultiplyPositionᶻDCommand(const MultiplyPositionᶻDCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyPositionᶻDCommand::~MultiplyPositionᶻDCommand()
    {
    }

    PostCPtr    MultiplyPositionᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionᶻDCommand(*this, h);
    }
    
    void MultiplyPositionᶻDCommand::init_meta()
    {
        auto w = writer<MultiplyPositionᶻDCommand>();
        w.description("Multiply Position Command");
        w.property("δz", &MultiplyPositionᶻDCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
