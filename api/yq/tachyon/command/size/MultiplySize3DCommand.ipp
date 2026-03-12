////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize³DCommand)

namespace yq::tachyon {
    MultiplySize³DCommand::MultiplySize³DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize³DCommand::MultiplySize³DCommand(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize³DCommand::MultiplySize³DCommand(const MultiplySize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize³DCommand::~MultiplySize³DCommand()
    {
    }

    PostCPtr    MultiplySize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize³DCommand(*this, h);
    }
    
    void MultiplySize³DCommand::init_meta()
    {
        auto w = writer<MultiplySize³DCommand>();
        w.description("Multiply Size DCommand");
        w.property("δx", &MultiplySize³DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize³DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplySize³DCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplySize³DCommand::m_δ).tag(kTag_Save);
    }
}
