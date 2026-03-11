////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPositionXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionˣDCommand)

namespace yq::tachyon {
    MultiplyPositionˣDCommand::MultiplyPositionˣDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MultiplyPositionˣDCommand::MultiplyPositionˣDCommand(const Header&h, double x) : 
        PositionCommand(h), m_δx(x)
    {
    }

    MultiplyPositionˣDCommand::MultiplyPositionˣDCommand(const MultiplyPositionˣDCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyPositionˣDCommand::~MultiplyPositionˣDCommand()
    {
    }
    
    PostCPtr    MultiplyPositionˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionˣDCommand(*this, h);
    }

    void MultiplyPositionˣDCommand::init_meta()
    {
        auto w = writer<MultiplyPositionˣDCommand>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPositionˣDCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
