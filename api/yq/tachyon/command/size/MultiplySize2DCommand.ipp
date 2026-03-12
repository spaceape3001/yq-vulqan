////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize²DCommand)

namespace yq::tachyon {
    MultiplySize²DCommand::MultiplySize²DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize²DCommand::MultiplySize²DCommand(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize²DCommand::MultiplySize²DCommand(const MultiplySize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize²DCommand::~MultiplySize²DCommand()
    {
    }

    PostCPtr    MultiplySize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize²DCommand(*this, h);
    }
    
    void MultiplySize²DCommand::init_meta()
    {
        auto w = writer<MultiplySize²DCommand>();
        w.description("Multiply Size DCommand");
        w.property("δx", &MultiplySize²DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize²DCommand::δy).tag(kTag_Log);
        w.property("δ", &MultiplySize²DCommand::m_δ).tag(kTag_Save);
    }
}
