////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize³DCommand)

namespace yq::tachyon {
    MultiplyMinSize³DCommand::MultiplyMinSize³DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize³DCommand::MultiplyMinSize³DCommand(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize³DCommand::MultiplyMinSize³DCommand(const MultiplyMinSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize³DCommand::~MultiplyMinSize³DCommand()
    {
    }

    PostCPtr    MultiplyMinSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize³DCommand(*this, h);
    }
    
    void MultiplyMinSize³DCommand::init_meta()
    {
        auto w = writer<MultiplyMinSize³DCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δx", &MultiplyMinSize³DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize³DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMinSize³DCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize³DCommand::m_δ).tag(kTag_Save);
    }
}
