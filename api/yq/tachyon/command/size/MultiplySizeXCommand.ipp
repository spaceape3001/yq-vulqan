////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeˣCommand)

namespace yq::tachyon {
    MultiplySizeˣCommand::MultiplySizeˣCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplySizeˣCommand::MultiplySizeˣCommand(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplySizeˣCommand::MultiplySizeˣCommand(const MultiplySizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplySizeˣCommand::~MultiplySizeˣCommand()
    {
    }
    
    PostCPtr    MultiplySizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeˣCommand(*this, h);
    }

    void MultiplySizeˣCommand::init_meta()
    {
        auto w = writer<MultiplySizeˣCommand>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySizeˣCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
