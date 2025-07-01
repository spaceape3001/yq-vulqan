////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeˣCommand)

namespace yq::tachyon {
    MultiplyMaxSizeˣCommand::MultiplyMaxSizeˣCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSizeˣCommand::MultiplyMaxSizeˣCommand(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplyMaxSizeˣCommand::MultiplyMaxSizeˣCommand(const MultiplyMaxSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyMaxSizeˣCommand::~MultiplyMaxSizeˣCommand()
    {
    }
    
    PostCPtr    MultiplyMaxSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeˣCommand(*this, h);
    }

    void MultiplyMaxSizeˣCommand::init_info()
    {
        auto w = writer<MultiplyMaxSizeˣCommand>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSizeˣCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
