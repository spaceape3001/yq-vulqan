////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScale1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale¹)

namespace yq::tachyon {
    MultiplyScale¹::MultiplyScale¹(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyScale¹::MultiplyScale¹(const Header& h, const Vector1D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplyScale¹::MultiplyScale¹(const MultiplyScale¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyScale¹::~MultiplyScale¹()
    {
    }
    
    PostCPtr    MultiplyScale¹::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale¹(*this, h);
    }

    void MultiplyScale¹::init_info()
    {
        auto w = writer<MultiplyScale¹>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale¹::δx).tag(kTag_Log);
        w.property("δ", &MultiplyScale¹::m_δ).tag(kTag_Save);
    }
}
