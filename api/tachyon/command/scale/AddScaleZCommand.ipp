////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScaleZCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleᶻCommand)

namespace yq::tachyon {
    AddScaleᶻCommand::AddScaleᶻCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    AddScaleᶻCommand::AddScaleᶻCommand(const Header&h, double z) : 
        ScaleCommand(h), m_Δz(z)
    {
    }

    AddScaleᶻCommand::AddScaleᶻCommand(const AddScaleᶻCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddScaleᶻCommand::~AddScaleᶻCommand()
    {
    }

    PostCPtr    AddScaleᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleᶻCommand(*this, h);
    }
    
    void AddScaleᶻCommand::init_info()
    {
        auto w = writer<AddScaleᶻCommand>();
        w.description("Add Scale Command in Z");
        w.property("Δz", &AddScaleᶻCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
