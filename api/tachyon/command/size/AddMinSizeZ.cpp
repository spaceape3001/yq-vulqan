////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMinSizeZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeᶻ)

namespace yq::tachyon {
    AddMinSizeᶻ::AddMinSizeᶻ(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMinSizeᶻ::AddMinSizeᶻ(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMinSizeᶻ::AddMinSizeᶻ(const AddMinSizeᶻ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMinSizeᶻ::~AddMinSizeᶻ()
    {
    }

    PostCPtr    AddMinSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeᶻ(*this, h);
    }
    
    void AddMinSizeᶻ::init_info()
    {
        auto w = writer<AddMinSizeᶻ>();
        w.description("AddMin Size Command in Z");
        w.property("Δz", &AddMinSizeᶻ::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
