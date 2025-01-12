////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMaxSize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize¹)

namespace yq::tachyon {
    MultiplyMaxSize¹::MultiplyMaxSize¹(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyMaxSize¹::MultiplyMaxSize¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize¹::MultiplyMaxSize¹(const MultiplyMaxSize¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyMaxSize¹::~MultiplyMaxSize¹()
    {
    }
    
    PostCPtr    MultiplyMaxSize¹::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize¹(*this, h);
    }

    void MultiplyMaxSize¹::init_info()
    {
        auto w = writer<MultiplyMaxSize¹>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize¹::δx).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize¹::m_δ).tag(kTag_Save);
    }
}
