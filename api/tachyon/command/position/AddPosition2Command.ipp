////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/AddPosition2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition²Command)

namespace yq::tachyon {
    AddPosition²Command::AddPosition²Command(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPosition²Command::AddPosition²Command(const Header&h, const Vector2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition²Command::AddPosition²Command(const AddPosition²Command& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition²Command::~AddPosition²Command()
    {
    }
    
    PostCPtr    AddPosition²Command::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition²Command(*this, h);
    }

    void AddPosition²Command::init_info()
    {
        auto w = writer<AddPosition²Command>();
        w.description("Position AddPosition Command in 2D");
        w.property("Δx", &AddPosition²Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition²Command::Δy).tag(kTag_Log);
        w.property("Δ", &AddPosition²Command::m_Δ).tag(kTag_Save);
    }
}
