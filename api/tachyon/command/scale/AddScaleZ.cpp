////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/AddScaleZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleᶻ)

namespace yq::tachyon {
    AddScaleᶻ::AddScaleᶻ(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    AddScaleᶻ::AddScaleᶻ(const Header&h, double z) : 
        ScaleCommand(h), m_Δz(z)
    {
    }

    AddScaleᶻ::AddScaleᶻ(const AddScaleᶻ& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddScaleᶻ::~AddScaleᶻ()
    {
    }

    PostCPtr    AddScaleᶻ::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleᶻ(*this, h);
    }
    
    void AddScaleᶻ::init_info()
    {
        auto w = writer<AddScaleᶻ>();
        w.description("Add Scale Command in Z");
        w.property("Δz", &AddScaleᶻ::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
