////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/scale/AddScale3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale³)

namespace yq::tachyon {
    AddScale³::AddScale³(const Header& h) : ScaleCommand(h)
    {
    }
    
    AddScale³::AddScale³(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }

    AddScale³::AddScale³(const AddScale³& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddScale³::~AddScale³()
    {
    }

    PostCPtr    AddScale³::clone(rebind_k, const Header&h) const 
    {
        return new AddScale³(*this, h);
    }
    
    void AddScale³::init_info()
    {
        auto w = writer<AddScale³>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale³::Δx).tag(kTag_Log);
        w.property("Δy", &AddScale³::Δy).tag(kTag_Log);
        w.property("Δz", &AddScale³::Δz).tag(kTag_Log);
        w.property("Δ",  &AddScale³::m_Δ).tag(kTag_Save);
    }
}
