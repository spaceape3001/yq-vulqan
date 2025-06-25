////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetWireframeCommand.hpp"
#include <tachyon/api/CommandInfoWriter.hpp>

namespace yq::tachyon {
    SetWireframeCommand::SetWireframeCommand(const Header& h, Tristate v) : RenderedCommand(h), m_wireframe(v)
    {
    }
    
    SetWireframeCommand::SetWireframeCommand(const SetWireframeCommand& cp, const Header& h) : 
        RenderedCommand(cp, h), m_wireframe(cp.m_wireframe)
    {
    }
    
    SetWireframeCommand::~SetWireframeCommand()
    {
    }
        
    PostCPtr    SetWireframeCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetWireframeCommand(*this, h);
    }

    void SetWireframeCommand::init_info()
    {
        auto w = writer<SetWireframeCommand>();
        w.description("Set Wireframe Command");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetWireframeCommand)
