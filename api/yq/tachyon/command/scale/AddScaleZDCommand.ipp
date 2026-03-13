////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScaleZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleᶻDCommand)

namespace yq::tachyon {
    AddScaleᶻDCommand::AddScaleᶻDCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    AddScaleᶻDCommand::AddScaleᶻDCommand(const Header&h, double z) : 
        ScaleCommand(h), m_Δz(z)
    {
    }

    AddScaleᶻDCommand::AddScaleᶻDCommand(const AddScaleᶻDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddScaleᶻDCommand::~AddScaleᶻDCommand()
    {
    }

    PostCPtr    AddScaleᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleᶻDCommand(*this, h);
    }
    
    void AddScaleᶻDCommand::init_meta()
    {
        auto w = writer<AddScaleᶻDCommand>();
        w.description("Add Scale Command in Z");
        w.property("Δz", &AddScaleᶻDCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
