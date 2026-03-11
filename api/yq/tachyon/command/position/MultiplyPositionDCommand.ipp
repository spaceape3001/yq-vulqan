////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPositionDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionDCommand)

namespace yq::tachyon {
    MultiplyPositionDCommand::MultiplyPositionDCommand(const Header&h, double f) : 
        PositionCommand(h), m_δ(f)
    {
    }

    MultiplyPositionDCommand::MultiplyPositionDCommand(const MultiplyPositionDCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPositionDCommand::MultiplyPositionDCommand(const Header&h) : PositionCommand(h)
    {
    }

    MultiplyPositionDCommand::~MultiplyPositionDCommand()
    {
    }
    
    PostCPtr    MultiplyPositionDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionDCommand(*this, h);
    }

    void MultiplyPositionDCommand::init_meta()
    {
        auto w = writer<MultiplyPositionDCommand>();
        w.description("Multiply Position Command");
        w.property("δ", &MultiplyPositionDCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
