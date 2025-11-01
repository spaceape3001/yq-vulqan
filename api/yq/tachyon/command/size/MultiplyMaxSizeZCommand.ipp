////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/MultiplyMaxSizeZCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeᶻCommand)

namespace yq::tachyon {
    MultiplyMaxSizeᶻCommand::MultiplyMaxSizeᶻCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSizeᶻCommand::MultiplyMaxSizeᶻCommand(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplyMaxSizeᶻCommand::MultiplyMaxSizeᶻCommand(const MultiplyMaxSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyMaxSizeᶻCommand::~MultiplyMaxSizeᶻCommand()
    {
    }

    PostCPtr    MultiplyMaxSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeᶻCommand(*this, h);
    }
    
    void MultiplyMaxSizeᶻCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSizeᶻCommand>();
        w.description("MultiplyMax Size Command");
        w.property("δz", &MultiplyMaxSizeᶻCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
