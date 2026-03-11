////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPosition2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition²DCommand)

namespace yq::tachyon {
    MultiplyPosition²DCommand::MultiplyPosition²DCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition²DCommand::MultiplyPosition²DCommand(const Header& h, const Vector2D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition²DCommand::MultiplyPosition²DCommand(const MultiplyPosition²DCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition²DCommand::~MultiplyPosition²DCommand()
    {
    }

    PostCPtr    MultiplyPosition²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition²DCommand(*this, h);
    }
    
    void MultiplyPosition²DCommand::init_meta()
    {
        auto w = writer<MultiplyPosition²DCommand>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition²DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition²DCommand::δy).tag(kTag_Log);
        w.property("δ", &MultiplyPosition²DCommand::m_δ).tag(kTag_Save);
    }
}
