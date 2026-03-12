////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize⁴DCommand)

namespace yq::tachyon {
    MultiplySize⁴DCommand::MultiplySize⁴DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize⁴DCommand::MultiplySize⁴DCommand(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize⁴DCommand::MultiplySize⁴DCommand(const MultiplySize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize⁴DCommand::~MultiplySize⁴DCommand()
    {
    }

    PostCPtr    MultiplySize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize⁴DCommand(*this, h);
    }
    
    void MultiplySize⁴DCommand::init_meta()
    {
        auto w = writer<MultiplySize⁴DCommand>();
        w.description("Multiply Size DCommand");
        w.property("δx", &MultiplySize⁴DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize⁴DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplySize⁴DCommand::δz).tag(kTag_Log);
        w.property("δw", &MultiplySize⁴DCommand::δw).tag(kTag_Log);
        w.property("δ", &MultiplySize⁴DCommand::m_δ).tag(kTag_Save);
    }
}
