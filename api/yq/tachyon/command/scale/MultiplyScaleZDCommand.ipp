////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyScaleZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleᶻDCommand)

namespace yq::tachyon {
    MultiplyScaleᶻDCommand::MultiplyScaleᶻDCommand(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScaleᶻDCommand::MultiplyScaleᶻDCommand(const Header&h, double z) : 
        ScaleCommand(h), m_δz(z)
    {
    }
    
    MultiplyScaleᶻDCommand::MultiplyScaleᶻDCommand(const MultiplyScaleᶻDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyScaleᶻDCommand::~MultiplyScaleᶻDCommand()
    {
    }

    PostCPtr    MultiplyScaleᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleᶻDCommand(*this, h);
    }
    
    void MultiplyScaleᶻDCommand::init_meta()
    {
        auto w = writer<MultiplyScaleᶻDCommand>();
        w.description("Multiply Scale Command");
        w.property("δz", &MultiplyScaleᶻDCommand::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
