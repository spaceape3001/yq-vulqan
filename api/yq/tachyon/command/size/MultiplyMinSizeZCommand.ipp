////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/MultiplyMinSizeZCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeᶻCommand)

namespace yq::tachyon {
    MultiplyMinSizeᶻCommand::MultiplyMinSizeᶻCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMinSizeᶻCommand::MultiplyMinSizeᶻCommand(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplyMinSizeᶻCommand::MultiplyMinSizeᶻCommand(const MultiplyMinSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyMinSizeᶻCommand::~MultiplyMinSizeᶻCommand()
    {
    }

    PostCPtr    MultiplyMinSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeᶻCommand(*this, h);
    }
    
    void MultiplyMinSizeᶻCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeᶻCommand>();
        w.description("MultiplyMin Size Command");
        w.property("δz", &MultiplyMinSizeᶻCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
