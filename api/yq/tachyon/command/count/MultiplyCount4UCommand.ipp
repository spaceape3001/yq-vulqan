////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount4UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount⁴UCommand)

namespace yq::tachyon {
    MultiplyCount⁴UCommand::MultiplyCount⁴UCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    MultiplyCount⁴UCommand::MultiplyCount⁴UCommand(const Header& h, const Vector4U& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount⁴UCommand::MultiplyCount⁴UCommand(const MultiplyCount⁴UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCount⁴UCommand::~MultiplyCount⁴UCommand()
    {
    }

    PostCPtr    MultiplyCount⁴UCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount⁴UCommand(*this, h);
    }
    
    void MultiplyCount⁴UCommand::init_meta()
    {
        auto w = writer<MultiplyCount⁴UCommand>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount⁴UCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyCount⁴UCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyCount⁴UCommand::δz).tag(kTag_Log);
        w.property("δw", &MultiplyCount⁴UCommand::δw).tag(kTag_Log);
        w.property("δ", &MultiplyCount⁴UCommand::m_δ).tag(kTag_Save);
    }
}
