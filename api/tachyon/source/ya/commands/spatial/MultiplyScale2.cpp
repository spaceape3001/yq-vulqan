////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScale2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale²)

namespace yq::tachyon {
    MultiplyScale²::MultiplyScale²(const Header& h, const Vector2D& v) : 
        SpatialCommand(h), m_scale(v)
    {
    }

    MultiplyScale²::MultiplyScale²(const MultiplyScale²& cp, const Header& h) : 
        SpatialCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    MultiplyScale²::~MultiplyScale²()
    {
    }

    PostCPtr    MultiplyScale²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale²(*this, h);
    }
    
    void MultiplyScale²::init_info()
    {
        auto w = writer<MultiplyScale²>();
        w.description("Multiply Scale Command");
        w.property("x", &MultiplyScale²::x);
        w.property("y", &MultiplyScale²::y);
    }
}
