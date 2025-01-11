////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddPosition3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition³)

namespace yq::tachyon {
    AddPosition³::AddPosition³(const Header&h) : 
        SpatialCommand(h)
    {
    }

    AddPosition³::AddPosition³(const Header&h, const Vector3D& Δ) : 
        SpatialCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition³::AddPosition³(const AddPosition³&cp, const Header&h) : 
        SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition³::~AddPosition³()
    {
    }

    PostCPtr    AddPosition³::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition³(*this, h);
    }
   
    void AddPosition³::init_info()
    {
        auto w = writer<AddPosition³>();
        w.description("Position AddPosition Command in 3D");
        w.property("Δx", &AddPosition³::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition³::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition³::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition³::m_Δ).tag(kTag_Save);
    }
}
