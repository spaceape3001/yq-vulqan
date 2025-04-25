////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/AddPosition4.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition⁴)

namespace yq::tachyon {
    AddPosition⁴::AddPosition⁴(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition⁴::AddPosition⁴(const Header&h, const Vector4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition⁴::AddPosition⁴(const AddPosition⁴&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition⁴::~AddPosition⁴()
    {
    }

    PostCPtr    AddPosition⁴::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition⁴(*this, h);
    }
   
    void AddPosition⁴::init_info()
    {
        auto w = writer<AddPosition⁴>();
        w.description("Position AddPosition Command in 4D");
        w.property("Δw", &AddPosition⁴::Δw).tag(kTag_Log);
        w.property("Δx", &AddPosition⁴::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition⁴::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition⁴::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition⁴::m_Δ).tag(kTag_Save);
    }
}
