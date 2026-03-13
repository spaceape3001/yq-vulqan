////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyCount2UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyCount²UCommand)

namespace yq::tachyon {
    MultiplyCount²UCommand::MultiplyCount²UCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    MultiplyCount²UCommand::MultiplyCount²UCommand(const Header& h, const Vector2U& v) : 
        CountCommand(h), m_δ(v)
    {
    }

    MultiplyCount²UCommand::MultiplyCount²UCommand(const MultiplyCount²UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyCount²UCommand::~MultiplyCount²UCommand()
    {
    }

    PostCPtr    MultiplyCount²UCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyCount²UCommand(*this, h);
    }
    
    void MultiplyCount²UCommand::init_meta()
    {
        auto w = writer<MultiplyCount²UCommand>();
        w.description("Multiply Count Command");
        w.property("δx", &MultiplyCount²UCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyCount²UCommand::δy).tag(kTag_Log);
        w.property("δ", &MultiplyCount²UCommand::m_δ).tag(kTag_Save);
    }
}
