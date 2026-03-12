////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize¹DCommand)

namespace yq::tachyon {
    MultiplyMaxSize¹DCommand::MultiplyMaxSize¹DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSize¹DCommand::MultiplyMaxSize¹DCommand(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize¹DCommand::MultiplyMaxSize¹DCommand(const MultiplyMaxSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyMaxSize¹DCommand::~MultiplyMaxSize¹DCommand()
    {
    }
    
    PostCPtr    MultiplyMaxSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize¹DCommand(*this, h);
    }

    void MultiplyMaxSize¹DCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSize¹DCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δx", &MultiplyMaxSize¹DCommand::δx).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize¹DCommand::m_δ).tag(kTag_Save);
    }
}
