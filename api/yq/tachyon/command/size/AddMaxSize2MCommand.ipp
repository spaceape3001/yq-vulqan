////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize²DCommand)

namespace yq::tachyon {
    AddMaxSize²DCommand::AddMaxSize²DCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMaxSize²DCommand::AddMaxSize²DCommand(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize²DCommand::AddMaxSize²DCommand(const AddMaxSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize²DCommand::~AddMaxSize²DCommand()
    {
    }

    PostCPtr    AddMaxSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize²DCommand(*this, h);
    }
    
    void AddMaxSize²DCommand::init_meta()
    {
        auto w = writer<AddMaxSize²DCommand>();
        w.description("AddMax Size DCommand");
        w.property("Δx", &AddMaxSize²DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize²DCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize²DCommand::m_Δ).tag(kTag_Save);
    }
}
