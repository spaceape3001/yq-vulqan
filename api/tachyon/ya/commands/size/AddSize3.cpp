////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddSize3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize³)

namespace yq::tachyon {
    AddSize³::AddSize³(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize³::AddSize³(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize³::AddSize³(const AddSize³& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize³::~AddSize³()
    {
    }

    PostCPtr    AddSize³::clone(rebind_k, const Header&h) const 
    {
        return new AddSize³(*this, h);
    }
    
    void AddSize³::init_info()
    {
        auto w = writer<AddSize³>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize³::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize³::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize³::Δz).tag(kTag_Log);
        w.property("Δ",  &AddSize³::m_Δ).tag(kTag_Save);
    }
}
