////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/AddPosition2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition²)

namespace yq::tachyon {
    AddPosition²::AddPosition²(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPosition²::AddPosition²(const Header&h, const Vector2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition²::AddPosition²(const AddPosition²& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition²::~AddPosition²()
    {
    }
    
    PostCPtr    AddPosition²::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition²(*this, h);
    }

    void AddPosition²::init_info()
    {
        auto w = writer<AddPosition²>();
        w.description("Position AddPosition Command in 2D");
        w.property("Δx", &AddPosition²::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition²::Δy).tag(kTag_Log);
        w.property("Δ", &AddPosition²::m_Δ).tag(kTag_Save);
    }
}
