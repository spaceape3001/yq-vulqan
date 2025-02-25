////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/scale/MultiplyScale2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale²)

namespace yq::tachyon {
    MultiplyScale²::MultiplyScale²(const Header& h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScale²::MultiplyScale²(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale²::MultiplyScale²(const MultiplyScale²& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale²::~MultiplyScale²()
    {
    }

    PostCPtr    MultiplyScale²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale²(*this, h);
    }
    
    void MultiplyScale²::init_info()
    {
        auto w = writer<MultiplyScale²>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale²::δx).tag(kTag_Log);
        w.property("δy", &MultiplyScale²::δy).tag(kTag_Log);
        w.property("δ", &MultiplyScale²::m_δ).tag(kTag_Save);
    }
}
