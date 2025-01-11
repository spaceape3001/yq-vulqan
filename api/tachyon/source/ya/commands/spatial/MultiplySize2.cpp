////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplySize2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize²)

namespace yq::tachyon {
    MultiplySize²::MultiplySize²(const Header& h) : 
        SpatialCommand(h)
    {
    }

    MultiplySize²::MultiplySize²(const Header& h, const Vector2D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplySize²::MultiplySize²(const MultiplySize²& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize²::~MultiplySize²()
    {
    }

    PostCPtr    MultiplySize²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize²(*this, h);
    }
    
    void MultiplySize²::init_info()
    {
        auto w = writer<MultiplySize²>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize²::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize²::δy).tag(kTag_Log);
        w.property("δ", &MultiplySize²::m_δ).tag(kTag_Save);
    }
}
