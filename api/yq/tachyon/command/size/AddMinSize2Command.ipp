////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize²Command)

namespace yq::tachyon {
    AddMinSize²Command::AddMinSize²Command(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMinSize²Command::AddMinSize²Command(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize²Command::AddMinSize²Command(const AddMinSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize²Command::~AddMinSize²Command()
    {
    }

    PostCPtr    AddMinSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize²Command(*this, h);
    }
    
    void AddMinSize²Command::init_meta()
    {
        auto w = writer<AddMinSize²Command>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize²Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize²Command::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMinSize²Command::m_Δ).tag(kTag_Save);
    }
}
