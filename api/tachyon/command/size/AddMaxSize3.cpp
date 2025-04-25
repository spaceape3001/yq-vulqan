////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSize3.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize³)

namespace yq::tachyon {
    AddMaxSize³::AddMaxSize³(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize³::AddMaxSize³(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize³::AddMaxSize³(const AddMaxSize³& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize³::~AddMaxSize³()
    {
    }

    PostCPtr    AddMaxSize³::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize³(*this, h);
    }
    
    void AddMaxSize³::init_info()
    {
        auto w = writer<AddMaxSize³>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize³::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize³::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize³::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize³::m_Δ).tag(kTag_Save);
    }
}
