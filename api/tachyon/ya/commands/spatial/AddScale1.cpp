////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScale1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale¹)

namespace yq::tachyon {
    AddScale¹::AddScale¹(const Header& h) : SpatialCommand(h)
    {
    }

    AddScale¹::AddScale¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_Δ(v)
    {
    }
    
    AddScale¹::AddScale¹(const AddScale¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddScale¹::~AddScale¹()
    {
    }
    
    PostCPtr    AddScale¹::clone(rebind_k, const Header&h) const 
    {
        return new AddScale¹(*this, h);
    }

    void AddScale¹::init_info()
    {
        auto w = writer<AddScale¹>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale¹::Δx).tag(kTag_Log);
        w.property("Δ",  &AddScale¹::m_Δ).tag(kTag_Save);
    }
}
