////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/AddPosition3Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition³Command)

namespace yq::tachyon {
    AddPosition³Command::AddPosition³Command(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition³Command::AddPosition³Command(const Header&h, const Vector3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition³Command::AddPosition³Command(const AddPosition³Command&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition³Command::~AddPosition³Command()
    {
    }

    PostCPtr    AddPosition³Command::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition³Command(*this, h);
    }
   
    void AddPosition³Command::init_info()
    {
        auto w = writer<AddPosition³Command>();
        w.description("Position AddPosition Command in 3D");
        w.property("Δx", &AddPosition³Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition³Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition³Command::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition³Command::m_Δ).tag(kTag_Save);
    }
}
