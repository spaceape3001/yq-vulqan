////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScale1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale¹DCommand)

namespace yq::tachyon {
    MultiplyScale¹DCommand::MultiplyScale¹DCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScale¹DCommand::MultiplyScale¹DCommand(const Header& h, const Vector1D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale¹DCommand::MultiplyScale¹DCommand(const MultiplyScale¹DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyScale¹DCommand::~MultiplyScale¹DCommand()
    {
    }
    
    PostCPtr    MultiplyScale¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale¹DCommand(*this, h);
    }

    void MultiplyScale¹DCommand::init_meta()
    {
        auto w = writer<MultiplyScale¹DCommand>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale¹DCommand::δx).tag(kTag_Log);
        w.property("δ", &MultiplyScale¹DCommand::m_δ).tag(kTag_Save);
    }
}
