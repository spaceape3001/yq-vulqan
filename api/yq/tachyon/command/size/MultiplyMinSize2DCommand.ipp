////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize²DCommand)

namespace yq::tachyon {
    MultiplyMinSize²DCommand::MultiplyMinSize²DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize²DCommand::MultiplyMinSize²DCommand(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize²DCommand::MultiplyMinSize²DCommand(const MultiplyMinSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize²DCommand::~MultiplyMinSize²DCommand()
    {
    }

    PostCPtr    MultiplyMinSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize²DCommand(*this, h);
    }
    
    void MultiplyMinSize²DCommand::init_meta()
    {
        auto w = writer<MultiplyMinSize²DCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δx", &MultiplyMinSize²DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize²DCommand::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize²DCommand::m_δ).tag(kTag_Save);
    }
}
