////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/scale/MultiplyScaleZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleᶻ)

namespace yq::tachyon {
    MultiplyScaleᶻ::MultiplyScaleᶻ(const Header&h) : 
        ScaleCommand(h)
    {
    }
    
    MultiplyScaleᶻ::MultiplyScaleᶻ(const Header&h, double z) : 
        ScaleCommand(h), m_δz(z)
    {
    }
    
    MultiplyScaleᶻ::MultiplyScaleᶻ(const MultiplyScaleᶻ& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δz(cp.m_δz)
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
        w.property("δz", &MultiplyScaleᶻ::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
