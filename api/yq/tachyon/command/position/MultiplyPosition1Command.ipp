////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPosition1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition¹DCommand)

namespace yq::tachyon {
    MultiplyPosition¹DCommand::MultiplyPosition¹DCommand(const Header& h) : 
        PositionCommand(h)
    {
    }
    
    MultiplyPosition¹DCommand::MultiplyPosition¹DCommand(const Header& h, const Vector1D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition¹DCommand::MultiplyPosition¹DCommand(const MultiplyPosition¹DCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyPosition¹DCommand::~MultiplyPosition¹DCommand()
    {
    }
    
    PostCPtr    MultiplyPosition¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition¹DCommand(*this, h);
    }

    void MultiplyPosition¹DCommand::init_meta()
    {
        auto w = writer<MultiplyPosition¹DCommand>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition¹DCommand::δx).tag(kTag_Log);
        w.property("δ", &MultiplyPosition¹DCommand::m_δ).tag(kTag_Save);
    }
}
