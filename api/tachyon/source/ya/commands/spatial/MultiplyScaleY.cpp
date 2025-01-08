////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScaleY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleʸ)

namespace yq::tachyon {
    MultiplyScaleʸ::MultiplyScaleʸ(const Header& h, double y) : 
        SpatialCommand(h), m_y(y)
    {
    }
    
    MultiplyScaleʸ::MultiplyScaleʸ(const MultiplyScaleʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_y(cp.m_y)
    {
    }

    MultiplyScaleʸ::~MultiplyScaleʸ()
    {
    }

    PostCPtr    MultiplyScaleʸ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleʸ(*this, h);
    }
    
    void MultiplyScaleʸ::init_info()
    {
        auto w = writer<MultiplyScaleʸ>();
        w.description("Multiply Scale Command");
        w.property("y", &MultiplyScaleʸ::y);
    }
}
