////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeᶻMCommand)

namespace yq::tachyon {
    AddMaxSizeᶻMCommand::AddMaxSizeᶻMCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMaxSizeᶻMCommand::AddMaxSizeᶻMCommand(const Header&h, Meter z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMaxSizeᶻMCommand::AddMaxSizeᶻMCommand(const AddMaxSizeᶻMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMaxSizeᶻMCommand::~AddMaxSizeᶻMCommand()
    {
    }

    PostCPtr    AddMaxSizeᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeᶻMCommand(*this, h);
    }
    
    void AddMaxSizeᶻMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeᶻMCommand>();
        w.description("AddMax Size MCommand in Z");
        w.property("Δz", &AddMaxSizeᶻMCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
