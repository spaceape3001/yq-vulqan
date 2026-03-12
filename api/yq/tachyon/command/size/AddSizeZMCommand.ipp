////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeᶻDCommand)

namespace yq::tachyon {
    AddSizeᶻDCommand::AddSizeᶻDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddSizeᶻDCommand::AddSizeᶻDCommand(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddSizeᶻDCommand::AddSizeᶻDCommand(const AddSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddSizeᶻDCommand::~AddSizeᶻDCommand()
    {
    }

    PostCPtr    AddSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeᶻDCommand(*this, h);
    }
    
    void AddSizeᶻDCommand::init_meta()
    {
        auto w = writer<AddSizeᶻDCommand>();
        w.description("Add Size DCommand in Z");
        w.property("Δz", &AddSizeᶻDCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
