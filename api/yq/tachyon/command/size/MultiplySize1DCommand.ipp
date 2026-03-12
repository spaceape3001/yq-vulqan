////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize¹DCommand)

namespace yq::tachyon {
    MultiplySize¹DCommand::MultiplySize¹DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySize¹DCommand::MultiplySize¹DCommand(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize¹DCommand::MultiplySize¹DCommand(const MultiplySize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplySize¹DCommand::~MultiplySize¹DCommand()
    {
    }
    
    PostCPtr    MultiplySize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize¹DCommand(*this, h);
    }

    void MultiplySize¹DCommand::init_meta()
    {
        auto w = writer<MultiplySize¹DCommand>();
        w.description("Multiply Size DCommand");
        w.property("δx", &MultiplySize¹DCommand::δx).tag(kTag_Log);
        w.property("δ", &MultiplySize¹DCommand::m_δ).tag(kTag_Save);
    }
}
