////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPosition3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition³DCommand)

namespace yq::tachyon {
    MultiplyPosition³DCommand::MultiplyPosition³DCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition³DCommand::MultiplyPosition³DCommand(const Header& h, const Vector3D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition³DCommand::MultiplyPosition³DCommand(const MultiplyPosition³DCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition³DCommand::~MultiplyPosition³DCommand()
    {
    }

    PostCPtr    MultiplyPosition³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition³DCommand(*this, h);
    }
    
    void MultiplyPosition³DCommand::init_meta()
    {
        auto w = writer<MultiplyPosition³DCommand>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition³DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition³DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyPosition³DCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplyPosition³DCommand::m_δ).tag(kTag_Save);
    }
}
