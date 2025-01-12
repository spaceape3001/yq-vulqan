////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMinSize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize¹)

namespace yq::tachyon {
    MultiplyMinSize¹::MultiplyMinSize¹(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyMinSize¹::MultiplyMinSize¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize¹::MultiplyMinSize¹(const MultiplyMinSize¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyMinSize¹::~MultiplyMinSize¹()
    {
    }
    
    PostCPtr    MultiplyMinSize¹::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize¹(*this, h);
    }

    void MultiplyMinSize¹::init_info()
    {
        auto w = writer<MultiplyMinSize¹>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize¹::δx).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize¹::m_δ).tag(kTag_Save);
    }
}
