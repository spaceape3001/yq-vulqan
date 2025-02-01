////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplySize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize¹)

namespace yq::tachyon {
    MultiplySize¹::MultiplySize¹(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplySize¹::MultiplySize¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplySize¹::MultiplySize¹(const MultiplySize¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplySize¹::~MultiplySize¹()
    {
    }
    
    PostCPtr    MultiplySize¹::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize¹(*this, h);
    }

    void MultiplySize¹::init_info()
    {
        auto w = writer<MultiplySize¹>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize¹::δx).tag(kTag_Log);
        w.property("δ", &MultiplySize¹::m_δ).tag(kTag_Save);
    }
}
