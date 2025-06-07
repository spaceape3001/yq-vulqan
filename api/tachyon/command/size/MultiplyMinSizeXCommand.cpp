////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeˣCommand)

namespace yq::tachyon {
    MultiplyMinSizeˣCommand::MultiplyMinSizeˣCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSizeˣCommand::MultiplyMinSizeˣCommand(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplyMinSizeˣCommand::MultiplyMinSizeˣCommand(const MultiplyMinSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyMinSizeˣCommand::~MultiplyMinSizeˣCommand()
    {
    }
    
    PostCPtr    MultiplyMinSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeˣCommand(*this, h);
    }

    void MultiplyMinSizeˣCommand::init_info()
    {
        auto w = writer<MultiplyMinSizeˣCommand>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSizeˣCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
