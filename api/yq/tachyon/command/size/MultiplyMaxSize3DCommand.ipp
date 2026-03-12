////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize³DCommand)

namespace yq::tachyon {
    MultiplyMaxSize³DCommand::MultiplyMaxSize³DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize³DCommand::MultiplyMaxSize³DCommand(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize³DCommand::MultiplyMaxSize³DCommand(const MultiplyMaxSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize³DCommand::~MultiplyMaxSize³DCommand()
    {
    }

    PostCPtr    MultiplyMaxSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize³DCommand(*this, h);
    }
    
    void MultiplyMaxSize³DCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSize³DCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δx", &MultiplyMaxSize³DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize³DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMaxSize³DCommand::δz).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize³DCommand::m_δ).tag(kTag_Save);
    }
}
