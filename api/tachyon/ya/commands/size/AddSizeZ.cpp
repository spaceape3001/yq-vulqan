////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/AddSizeZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeᶻ)

namespace yq::tachyon {
    AddSizeᶻ::AddSizeᶻ(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddSizeᶻ::AddSizeᶻ(const Header&h, double z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddSizeᶻ::AddSizeᶻ(const AddSizeᶻ& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddSizeᶻ::~AddSizeᶻ()
    {
    }

    PostCPtr    AddSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeᶻ(*this, h);
    }
    
    void AddSizeᶻ::init_info()
    {
        auto w = writer<AddSizeᶻ>();
        w.description("Add Size Command in Z");
        w.property("Δz", &AddSizeᶻ::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
