////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScale2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale²Command)

namespace yq::tachyon {
    AddScale²Command::AddScale²Command(const Header&h) : ScaleCommand(h)
    {
    }
    
    AddScale²Command::AddScale²Command(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }

    AddScale²Command::AddScale²Command(const AddScale²Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddScale²Command::~AddScale²Command()
    {
    }

    PostCPtr    AddScale²Command::clone(rebind_k, const Header&h) const 
    {
        return new AddScale²Command(*this, h);
    }
    
    void AddScale²Command::init_meta()
    {
        auto w = writer<AddScale²Command>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale²Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddScale²Command::Δy).tag(kTag_Log);
        w.property("Δ",  &AddScale²Command::m_Δ).tag(kTag_Save);
    }
}
