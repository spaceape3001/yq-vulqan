////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMinSize2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize²)

namespace yq::tachyon {
    MultiplyMinSize²::MultiplyMinSize²(const Header& h) : 
        SpatialCommand(h)
    {
    }

    MultiplyMinSize²::MultiplyMinSize²(const Header& h, const Vector2D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize²::MultiplyMinSize²(const MultiplyMinSize²& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize²::~MultiplyMinSize²()
    {
    }

    PostCPtr    MultiplyMinSize²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize²(*this, h);
    }
    
    void MultiplyMinSize²::init_info()
    {
        auto w = writer<MultiplyMinSize²>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize²::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize²::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize²::m_δ).tag(kTag_Save);
    }
}
