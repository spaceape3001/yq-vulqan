////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScale2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale²DCommand)

namespace yq::tachyon {
    MultiplyScale²DCommand::MultiplyScale²DCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScale²DCommand::MultiplyScale²DCommand(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale²DCommand::MultiplyScale²DCommand(const MultiplyScale²DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale²DCommand::~MultiplyScale²DCommand()
    {
    }

    PostCPtr    MultiplyScale²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale²DCommand(*this, h);
    }
    
    void MultiplyScale²DCommand::init_meta()
    {
        auto w = writer<MultiplyScale²DCommand>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale²DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyScale²DCommand::δy).tag(kTag_Log);
        w.property("δ", &MultiplyScale²DCommand::m_δ).tag(kTag_Save);
    }
}
