////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize¹DCommand)

namespace yq::tachyon {
    MultiplyMinSize¹DCommand::MultiplyMinSize¹DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMinSize¹DCommand::MultiplyMinSize¹DCommand(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize¹DCommand::MultiplyMinSize¹DCommand(const MultiplyMinSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyMinSize¹DCommand::~MultiplyMinSize¹DCommand()
    {
    }
    
    PostCPtr    MultiplyMinSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize¹DCommand(*this, h);
    }

    void MultiplyMinSize¹DCommand::init_meta()
    {
        auto w = writer<MultiplyMinSize¹DCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δx", &MultiplyMinSize¹DCommand::δx).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize¹DCommand::m_δ).tag(kTag_Save);
    }
}
