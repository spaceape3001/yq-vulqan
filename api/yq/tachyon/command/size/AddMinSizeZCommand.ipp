////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeᶻCommand)

namespace yq::tachyon {
    AddMinSizeᶻCommand::AddMinSizeᶻCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMinSizeᶻCommand::AddMinSizeᶻCommand(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMinSizeᶻCommand::AddMinSizeᶻCommand(const AddMinSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMinSizeᶻCommand::~AddMinSizeᶻCommand()
    {
    }

    PostCPtr    AddMinSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeᶻCommand(*this, h);
    }
    
    void AddMinSizeᶻCommand::init_meta()
    {
        auto w = writer<AddMinSizeᶻCommand>();
        w.description("AddMin Size Command in Z");
        w.property("Δz", &AddMinSizeᶻCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
