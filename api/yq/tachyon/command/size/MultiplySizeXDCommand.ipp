////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeˣDCommand)

namespace yq::tachyon {
    MultiplySizeˣDCommand::MultiplySizeˣDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplySizeˣDCommand::MultiplySizeˣDCommand(const Header&h, double x) : 
        SizeCommand(h), m_δx(x)
    {
    }

    MultiplySizeˣDCommand::MultiplySizeˣDCommand(const MultiplySizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplySizeˣDCommand::~MultiplySizeˣDCommand()
    {
    }
    
    PostCPtr    MultiplySizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeˣDCommand(*this, h);
    }

    void MultiplySizeˣDCommand::init_meta()
    {
        auto w = writer<MultiplySizeˣDCommand>();
        w.description("Multiply Size DCommand");
        w.property("δx", &MultiplySizeˣDCommand::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
