////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize⁴DCommand)

namespace yq::tachyon {
    MultiplyMinSize⁴DCommand::MultiplyMinSize⁴DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize⁴DCommand::MultiplyMinSize⁴DCommand(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize⁴DCommand::MultiplyMinSize⁴DCommand(const MultiplyMinSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize⁴DCommand::~MultiplyMinSize⁴DCommand()
    {
    }

    PostCPtr    MultiplyMinSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize⁴DCommand(*this, h);
    }
    
    void MultiplyMinSize⁴DCommand::init_meta()
    {
        auto w = writer<MultiplyMinSize⁴DCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δx", &MultiplyMinSize⁴DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize⁴DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMinSize⁴DCommand::δz).tag(kTag_Log);
        w.property("δw", &MultiplyMinSize⁴DCommand::δw).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize⁴DCommand::m_δ).tag(kTag_Save);
    }
}
