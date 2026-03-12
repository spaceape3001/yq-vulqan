////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize²DCommand)

namespace yq::tachyon {
    AddSize²DCommand::AddSize²DCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddSize²DCommand::AddSize²DCommand(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize²DCommand::AddSize²DCommand(const AddSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize²DCommand::~AddSize²DCommand()
    {
    }

    PostCPtr    AddSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize²DCommand(*this, h);
    }
    
    void AddSize²DCommand::init_meta()
    {
        auto w = writer<AddSize²DCommand>();
        w.description("Add Size DCommand");
        w.property("Δx", &AddSize²DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize²DCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddSize²DCommand::m_Δ).tag(kTag_Save);
    }
}
