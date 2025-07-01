////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionCommand)

namespace yq::tachyon {
    MultiplyPositionCommand::MultiplyPositionCommand(const Header&h, double f) : 
        PositionCommand(h), m_δ(f)
    {
    }

    MultiplyPositionCommand::MultiplyPositionCommand(const MultiplyPositionCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPositionCommand::MultiplyPositionCommand(const Header&h) : PositionCommand(h)
    {
    }

    MultiplyPositionCommand::~MultiplyPositionCommand()
    {
    }
    
    PostCPtr    MultiplyPositionCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionCommand(*this, h);
    }

    void MultiplyPositionCommand::init_info()
    {
        auto w = writer<MultiplyPositionCommand>();
        w.description("Multiply Position Command");
        w.property("δ", &MultiplyPositionCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
