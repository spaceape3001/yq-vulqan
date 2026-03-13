////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount1UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount¹UCommand)

namespace yq::tachyon {
    MultiplyCount¹UCommand::MultiplyCount¹UCommand(const Header& h) : 
        CountCommand(h)
    {
    }
    
    MultiplyCount¹UCommand::MultiplyCount¹UCommand(const Header& h, const Vector1U& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount¹UCommand::MultiplyCount¹UCommand(const MultiplyCount¹UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyCount¹UCommand::~MultiplyCount¹UCommand()
    {
    }
    
    PostCPtr    MultiplyCount¹UCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount¹UCommand(*this, h);
    }

    void MultiplyCount¹UCommand::init_meta()
    {
        auto w = writer<MultiplyCount¹UCommand>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount¹UCommand::δx).tag(kTag_Log);
        w.property("δ", &MultiplyCount¹UCommand::m_δ).tag(kTag_Save);
    }
}
