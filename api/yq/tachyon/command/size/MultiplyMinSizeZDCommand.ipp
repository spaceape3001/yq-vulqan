////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeᶻDCommand)

namespace yq::tachyon {
    MultiplyMinSizeᶻDCommand::MultiplyMinSizeᶻDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMinSizeᶻDCommand::MultiplyMinSizeᶻDCommand(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplyMinSizeᶻDCommand::MultiplyMinSizeᶻDCommand(const MultiplyMinSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyMinSizeᶻDCommand::~MultiplyMinSizeᶻDCommand()
    {
    }

    PostCPtr    MultiplyMinSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeᶻDCommand(*this, h);
    }
    
    void MultiplyMinSizeᶻDCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeᶻDCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δz", &MultiplyMinSizeᶻDCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
