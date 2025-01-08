////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScale3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale³)

namespace yq::tachyon {
    MultiplyScale³::MultiplyScale³(const Header& h, const Vector3D& v) : 
        SpatialCommand(h), m_scale(v)
    {
    }

    MultiplyScale³::MultiplyScale³(const MultiplyScale³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    MultiplyScale³::~MultiplyScale³()
    {
    }

    PostCPtr    MultiplyScale³::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale³(*this, h);
    }
    
    void MultiplyScale³::init_info()
    {
        auto w = writer<MultiplyScale³>();
        w.description("Multiply Scale Command");
        w.property("x", &MultiplyScale³::x);
        w.property("y", &MultiplyScale³::y);
        w.property("z", &MultiplyScale³::z);
    }
}
