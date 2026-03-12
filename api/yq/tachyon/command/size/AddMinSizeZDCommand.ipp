////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeᶻDCommand)

namespace yq::tachyon {
    AddMinSizeᶻDCommand::AddMinSizeᶻDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMinSizeᶻDCommand::AddMinSizeᶻDCommand(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMinSizeᶻDCommand::AddMinSizeᶻDCommand(const AddMinSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMinSizeᶻDCommand::~AddMinSizeᶻDCommand()
    {
    }

    PostCPtr    AddMinSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeᶻDCommand(*this, h);
    }
    
    void AddMinSizeᶻDCommand::init_meta()
    {
        auto w = writer<AddMinSizeᶻDCommand>();
        w.description("AddMin Size DCommand in Z");
        w.property("Δz", &AddMinSizeᶻDCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
