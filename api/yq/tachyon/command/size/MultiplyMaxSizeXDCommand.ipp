////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeˣDCommand)

namespace yq::tachyon {
    MultiplyMaxSizeˣDCommand::MultiplyMaxSizeˣDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSizeˣDCommand::MultiplyMaxSizeˣDCommand(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplyMaxSizeˣDCommand::MultiplyMaxSizeˣDCommand(const MultiplyMaxSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyMaxSizeˣDCommand::~MultiplyMaxSizeˣDCommand()
    {
    }
    
    PostCPtr    MultiplyMaxSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeˣDCommand(*this, h);
    }

    void MultiplyMaxSizeˣDCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSizeˣDCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δx", &MultiplyMaxSizeˣDCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
