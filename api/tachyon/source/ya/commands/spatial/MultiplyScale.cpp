////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScale.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale)

namespace yq::tachyon {
    MultiplyScale::MultiplyScale(const Header&h, double f) : 
        SpatialCommand(h), m_scale(f)
    {
    }

    MultiplyScale::MultiplyScale(const MultiplyScale& cp, const Header& h) : 
        SpatialCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    MultiplyScale::~MultiplyScale()
    {
    }
    
    PostCPtr    MultiplyScale::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale(*this, h);
    }

    void MultiplyScale::init_info()
    {
        auto w = writer<MultiplyScale>();
        w.description("Multiply Scale Command");
        w.property("f", &MultiplyScale::scale);
    }
}
