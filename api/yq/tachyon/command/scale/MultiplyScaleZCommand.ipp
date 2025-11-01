////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/MultiplyScaleZCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleᶻCommand)

namespace yq::tachyon {
    MultiplyScaleᶻCommand::MultiplyScaleᶻCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScaleᶻCommand::MultiplyScaleᶻCommand(const Header&h, double z) : 
        ScaleCommand(h), m_δz(z)
    {
    }
    
    MultiplyScaleᶻCommand::MultiplyScaleᶻCommand(const MultiplyScaleᶻCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyScaleᶻCommand::~MultiplyScaleᶻCommand()
    {
    }

    PostCPtr    MultiplyScaleᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleᶻCommand(*this, h);
    }
    
    void MultiplyScaleᶻCommand::init_meta()
    {
        auto w = writer<MultiplyScaleᶻCommand>();
        w.description("Multiply Scale Command");
        w.property("δz", &MultiplyScaleᶻCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
