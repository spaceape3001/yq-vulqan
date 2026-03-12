////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSizeDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeDCommand)

namespace yq::tachyon {
    MultiplyMaxSizeDCommand::MultiplyMaxSizeDCommand(const Header&h, double f) : 
        SizeCommand(h), m_δ(f)
    {
    }

    MultiplyMaxSizeDCommand::MultiplyMaxSizeDCommand(const MultiplyMaxSizeDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSizeDCommand::MultiplyMaxSizeDCommand(const Header&h) : SizeCommand(h)
    {
    }

    MultiplyMaxSizeDCommand::~MultiplyMaxSizeDCommand()
    {
    }
    
    PostCPtr    MultiplyMaxSizeDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeDCommand(*this, h);
    }

    void MultiplyMaxSizeDCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSizeDCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δ", &MultiplyMaxSizeDCommand::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
