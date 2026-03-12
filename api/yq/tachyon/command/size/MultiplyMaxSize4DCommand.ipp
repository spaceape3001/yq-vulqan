////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize⁴DCommand)

namespace yq::tachyon {
    MultiplyMaxSize⁴DCommand::MultiplyMaxSize⁴DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize⁴DCommand::MultiplyMaxSize⁴DCommand(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize⁴DCommand::MultiplyMaxSize⁴DCommand(const MultiplyMaxSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize⁴DCommand::~MultiplyMaxSize⁴DCommand()
    {
    }

    PostCPtr    MultiplyMaxSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize⁴DCommand(*this, h);
    }
    
    void MultiplyMaxSize⁴DCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSize⁴DCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δx", &MultiplyMaxSize⁴DCommand::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize⁴DCommand::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMaxSize⁴DCommand::δz).tag(kTag_Log);
        w.property("δw", &MultiplyMaxSize⁴DCommand::δw).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize⁴DCommand::m_δ).tag(kTag_Save);
    }
}
