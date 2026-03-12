////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize²DCommand)

namespace yq::tachyon {
    MultiplyMaxSize²DCommand::MultiplyMaxSize²DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize²DCommand::MultiplyMaxSize²DCommand(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize²DCommand::MultiplyMaxSize²DCommand(const MultiplyMaxSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize²DCommand::~MultiplyMaxSize²DCommand()
    {
    }

    PostCPtr    MultiplyMaxSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize²DCommand(*this, h);
    }
    
    void MultiplyMaxSize²DCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSize²DCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δx", &MultiplyMaxSize²DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize²DCommand::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize²DCommand::m_δ).tag(kTag_Save);
    }
}
