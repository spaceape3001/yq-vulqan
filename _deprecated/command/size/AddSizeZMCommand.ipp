////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeᶻMCommand)

namespace yq::tachyon {
    AddSizeᶻMCommand::AddSizeᶻMCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddSizeᶻMCommand::AddSizeᶻMCommand(const Header&h, Meter z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddSizeᶻMCommand::AddSizeᶻMCommand(const AddSizeᶻMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddSizeᶻMCommand::~AddSizeᶻMCommand()
    {
    }

    PostCPtr    AddSizeᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeᶻMCommand(*this, h);
    }
    
    void AddSizeᶻMCommand::init_meta()
    {
        auto w = writer<AddSizeᶻMCommand>();
        w.description("Add Size MCommand in Z");
        w.property("Δz", &AddSizeᶻMCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
