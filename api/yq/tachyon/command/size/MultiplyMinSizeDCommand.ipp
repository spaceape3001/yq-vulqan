////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSizeDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeDCommand)

namespace yq::tachyon {
    MultiplyMinSizeDCommand::MultiplyMinSizeDCommand(const Header&h, double f) : 
        SizeCommand(h), m_δ(f)
    {
    }

    MultiplyMinSizeDCommand::MultiplyMinSizeDCommand(const MultiplyMinSizeDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSizeDCommand::MultiplyMinSizeDCommand(const Header&h) : SizeCommand(h)
    {
    }

    MultiplyMinSizeDCommand::~MultiplyMinSizeDCommand()
    {
    }
    
    PostCPtr    MultiplyMinSizeDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeDCommand(*this, h);
    }

    void MultiplyMinSizeDCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeDCommand>();
        w.description("MultiplyMin Size Command");
        w.property("δ", &MultiplyMinSizeDCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
