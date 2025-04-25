////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPosition.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition)

namespace yq::tachyon {
    MultiplyPosition::MultiplyPosition(const Header&h, double f) : 
        PositionCommand(h), m_δ(f)
    {
    }

    MultiplyPosition::MultiplyPosition(const MultiplyPosition& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition::MultiplyPosition(const Header&h) : PositionCommand(h)
    {
    }

    MultiplyPosition::~MultiplyPosition()
    {
    }
    
    PostCPtr    MultiplyPosition::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition(*this, h);
    }

    void MultiplyPosition::init_info()
    {
        auto w = writer<MultiplyPosition>();
        w.description("Multiply Position Command");
        w.property("δ", &MultiplyPosition::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
