////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/AddPosition1.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition¹)

namespace yq::tachyon {
    AddPosition¹::AddPosition¹(const Header& h) : 
        PositionCommand(h)
    {
    }

    AddPosition¹::AddPosition¹(const Header& h, const Vector1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition¹::AddPosition¹(const AddPosition¹&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition¹::~AddPosition¹()
    {
    }
    
    PostCPtr    AddPosition¹::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition¹(*this, h);
    }

    void AddPosition¹::init_info()
    {
        auto w = writer<AddPosition¹>();
        w.description("Position AddPosition Command in 1D");
        w.property("Δx", &AddPosition¹::Δx).tag(kTag_Log);
        w.property("Δ", &AddPosition¹::m_Δ).tag(kTag_Save);
    }
}
