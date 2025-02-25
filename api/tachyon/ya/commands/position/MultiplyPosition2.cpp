////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/MultiplyPosition2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition²)

namespace yq::tachyon {
    MultiplyPosition²::MultiplyPosition²(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition²::MultiplyPosition²(const Header& h, const Vector2D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition²::MultiplyPosition²(const MultiplyPosition²& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition²::~MultiplyPosition²()
    {
    }

    PostCPtr    MultiplyPosition²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition²(*this, h);
    }
    
    void MultiplyPosition²::init_info()
    {
        auto w = writer<MultiplyPosition²>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition²::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition²::δy).tag(kTag_Log);
        w.property("δ", &MultiplyPosition²::m_δ).tag(kTag_Save);
    }
}
