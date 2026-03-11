////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPosition4Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition⁴DCommand)

namespace yq::tachyon {
    MultiplyPosition⁴DCommand::MultiplyPosition⁴DCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition⁴DCommand::MultiplyPosition⁴DCommand(const Header& h, const Vector4D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition⁴DCommand::MultiplyPosition⁴DCommand(const MultiplyPosition⁴DCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition⁴DCommand::~MultiplyPosition⁴DCommand()
    {
    }

    PostCPtr    MultiplyPosition⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition⁴DCommand(*this, h);
    }
    
    void MultiplyPosition⁴DCommand::init_meta()
    {
        auto w = writer<MultiplyPosition⁴DCommand>();
        w.description("Multiply Position Command");
        w.property("δw", &MultiplyPosition⁴DCommand::δw).tag(kTag_Log);
        w.property("δx", &MultiplyPosition⁴DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition⁴DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyPosition⁴DCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplyPosition⁴DCommand::m_δ).tag(kTag_Save);
    }
}
