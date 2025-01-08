////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleˣ)

namespace yq::tachyon {
    MultiplyScaleˣ::MultiplyScaleˣ(const Header&h, double x) : 
        SpatialCommand(h), m_x(x)
    {
    }

    MultiplyScaleˣ::MultiplyScaleˣ(const MultiplyScaleˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    MultiplyScaleˣ::~MultiplyScaleˣ()
    {
    }
    
    PostCPtr    MultiplyScaleˣ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleˣ(*this, h);
    }

    void MultiplyScaleˣ::init_info()
    {
        auto w = writer<MultiplyScaleˣ>();
        w.description("Multiply Scale Command");
        w.property("x", &MultiplyScaleˣ::x);
    }
}
