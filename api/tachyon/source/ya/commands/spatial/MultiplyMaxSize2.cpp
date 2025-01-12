////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMaxSize2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize²)

namespace yq::tachyon {
    MultiplyMaxSize²::MultiplyMaxSize²(const Header& h) : 
        SpatialCommand(h)
    {
    }

    MultiplyMaxSize²::MultiplyMaxSize²(const Header& h, const Vector2D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize²::MultiplyMaxSize²(const MultiplyMaxSize²& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize²::~MultiplyMaxSize²()
    {
    }

    PostCPtr    MultiplyMaxSize²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize²(*this, h);
    }
    
    void MultiplyMaxSize²::init_info()
    {
        auto w = writer<MultiplyMaxSize²>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize²::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize²::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize²::m_δ).tag(kTag_Save);
    }
}
