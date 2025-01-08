////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScaleZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleᶻ)

namespace yq::tachyon {
    AddScaleᶻ::AddScaleᶻ(const Header&h, double z) : 
        SpatialCommand(h), m_z(z)
    {
    }
    
    AddScaleᶻ::AddScaleᶻ(const AddScaleᶻ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_z(cp.m_z)
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
        w.description("Add Scale Command");
        w.property("z", &AddScaleᶻ::z);
    }
}
