////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize²DCommand)

namespace yq::tachyon {
    AddMinSize²DCommand::AddMinSize²DCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMinSize²DCommand::AddMinSize²DCommand(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize²DCommand::AddMinSize²DCommand(const AddMinSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize²DCommand::~AddMinSize²DCommand()
    {
    }

    PostCPtr    AddMinSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize²DCommand(*this, h);
    }
    
    void AddMinSize²DCommand::init_meta()
    {
        auto w = writer<AddMinSize²DCommand>();
        w.description("AddMin Size DCommand");
        w.property("Δx", &AddMinSize²DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize²DCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMinSize²DCommand::m_Δ).tag(kTag_Save);
    }
}
