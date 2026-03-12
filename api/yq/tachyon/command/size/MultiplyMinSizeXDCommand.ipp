////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeˣDCommand)

namespace yq::tachyon {
    MultiplyMinSizeˣDCommand::MultiplyMinSizeˣDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSizeˣDCommand::MultiplyMinSizeˣDCommand(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplyMinSizeˣDCommand::MultiplyMinSizeˣDCommand(const MultiplyMinSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyMinSizeˣDCommand::~MultiplyMinSizeˣDCommand()
    {
    }
    
    PostCPtr    MultiplyMinSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeˣDCommand(*this, h);
    }

    void MultiplyMinSizeˣDCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeˣDCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δx", &MultiplyMinSizeˣDCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
