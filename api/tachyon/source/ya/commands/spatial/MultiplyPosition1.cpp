////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyPosition1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition¹)

namespace yq::tachyon {
    MultiplyPosition¹::MultiplyPosition¹(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyPosition¹::MultiplyPosition¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplyPosition¹::MultiplyPosition¹(const MultiplyPosition¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyPosition¹::~MultiplyPosition¹()
    {
    }
    
    PostCPtr    MultiplyPosition¹::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition¹(*this, h);
    }

    void MultiplyPosition¹::init_info()
    {
        auto w = writer<MultiplyPosition¹>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition¹::δx).tag(kTag_Log);
        w.property("δ", &MultiplyPosition¹::m_δ).tag(kTag_Save);
    }
}
