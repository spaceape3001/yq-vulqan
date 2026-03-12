////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeᶻDCommand)

namespace yq::tachyon {
    MultiplySizeᶻDCommand::MultiplySizeᶻDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySizeᶻDCommand::MultiplySizeᶻDCommand(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplySizeᶻDCommand::MultiplySizeᶻDCommand(const MultiplySizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplySizeᶻDCommand::~MultiplySizeᶻDCommand()
    {
    }

    PostCPtr    MultiplySizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeᶻDCommand(*this, h);
    }
    
    void MultiplySizeᶻDCommand::init_meta()
    {
        auto w = writer<MultiplySizeᶻDCommand>();
        w.description("Multiply Size DCommand");
        w.property("δz", &MultiplySizeᶻDCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
