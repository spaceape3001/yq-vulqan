////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScaleZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleᶻ)

namespace yq::tachyon {
    MultiplyScaleᶻ::MultiplyScaleᶻ(const Header&h, double z) : 
        SpatialCommand(h), m_z(z)
    {
    }
    
    MultiplyScaleᶻ::MultiplyScaleᶻ(const MultiplyScaleᶻ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_z(cp.m_z)
    {
    }

    MultiplyScaleᶻ::~MultiplyScaleᶻ()
    {
    }

    PostCPtr    MultiplyScaleᶻ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleᶻ(*this, h);
    }
    
    void MultiplyScaleᶻ::init_info()
    {
        auto w = writer<MultiplyScaleᶻ>();
        w.description("Multiply Scale Command");
        w.property("z", &MultiplyScaleᶻ::z);
    }
}
