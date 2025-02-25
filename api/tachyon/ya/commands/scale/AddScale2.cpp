////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/scale/AddScale2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale²)

namespace yq::tachyon {
    AddScale²::AddScale²(const Header&h) : ScaleCommand(h)
    {
    }
    
    AddScale²::AddScale²(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }

    AddScale²::AddScale²(const AddScale²& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddScale²::~AddScale²()
    {
    }

    PostCPtr    AddScale²::clone(rebind_k, const Header&h) const 
    {
        return new AddScale²(*this, h);
    }
    
    void AddScale²::init_info()
    {
        auto w = writer<AddScale²>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale²::Δx).tag(kTag_Log);
        w.property("Δy", &AddScale²::Δy).tag(kTag_Log);
        w.property("Δ",  &AddScale²::m_Δ).tag(kTag_Save);
    }
}
