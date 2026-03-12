////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMaxSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSizeᶻDCommand)

namespace yq::tachyon {
    MultiplyMaxSizeᶻDCommand::MultiplyMaxSizeᶻDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSizeᶻDCommand::MultiplyMaxSizeᶻDCommand(const Header&h, double z) : 
        SizeCommand(h), m_δz(z)
    {
    }
    
    MultiplyMaxSizeᶻDCommand::MultiplyMaxSizeᶻDCommand(const MultiplyMaxSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyMaxSizeᶻDCommand::~MultiplyMaxSizeᶻDCommand()
    {
    }

    PostCPtr    MultiplyMaxSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSizeᶻDCommand(*this, h);
    }
    
    void MultiplyMaxSizeᶻDCommand::init_meta()
    {
        auto w = writer<MultiplyMaxSizeᶻDCommand>();
        w.description("MultiplyMax Size DCommand");
        w.property("δz", &MultiplyMaxSizeᶻDCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
