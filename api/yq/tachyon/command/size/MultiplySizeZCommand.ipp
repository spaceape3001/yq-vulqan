////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/MultiplySizeZCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeᶻCommand)

namespace yq::tachyon {
    MultiplySizeᶻCommand::MultiplySizeᶻCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySizeᶻCommand::MultiplySizeᶻCommand(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplySizeᶻCommand::MultiplySizeᶻCommand(const MultiplySizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplySizeᶻCommand::~MultiplySizeᶻCommand()
    {
    }

    PostCPtr    MultiplySizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeᶻCommand(*this, h);
    }
    
    void MultiplySizeᶻCommand::init_meta()
    {
        auto w = writer<MultiplySizeᶻCommand>();
        w.description("Multiply Size Command");
        w.property("δz", &MultiplySizeᶻCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
