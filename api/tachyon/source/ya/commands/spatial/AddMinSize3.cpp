////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddMinSize3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize³)

namespace yq::tachyon {
    AddMinSize³::AddMinSize³(const Header& h) : SpatialCommand(h)
    {
    }
    
    AddMinSize³::AddMinSize³(const Header& h, const Vector3D& v) : 
        SpatialCommand(h), m_Δ(v)
    {
    }

    AddMinSize³::AddMinSize³(const AddMinSize³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize³::~AddMinSize³()
    {
    }

    PostCPtr    AddMinSize³::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize³(*this, h);
    }
    
    void AddMinSize³::init_info()
    {
        auto w = writer<AddMinSize³>();
        w.description("AddMin Size Command");
        w.property("Δx", &AddMinSize³::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize³::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize³::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMinSize³::m_Δ).tag(kTag_Save);
    }
}
