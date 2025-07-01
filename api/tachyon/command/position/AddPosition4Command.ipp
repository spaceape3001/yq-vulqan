////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/AddPosition4Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition⁴Command)

namespace yq::tachyon {
    AddPosition⁴Command::AddPosition⁴Command(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition⁴Command::AddPosition⁴Command(const Header&h, const Vector4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition⁴Command::AddPosition⁴Command(const AddPosition⁴Command&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition⁴Command::~AddPosition⁴Command()
    {
    }

    PostCPtr    AddPosition⁴Command::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition⁴Command(*this, h);
    }
   
    void AddPosition⁴Command::init_meta()
    {
        auto w = writer<AddPosition⁴Command>();
        w.description("Position AddPosition Command in 4D");
        w.property("Δw", &AddPosition⁴Command::Δw).tag(kTag_Log);
        w.property("Δx", &AddPosition⁴Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition⁴Command::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition⁴Command::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition⁴Command::m_Δ).tag(kTag_Save);
    }
}
