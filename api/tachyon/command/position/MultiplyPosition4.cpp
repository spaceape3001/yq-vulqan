////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPosition4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition⁴)

namespace yq::tachyon {
    MultiplyPosition⁴::MultiplyPosition⁴(const Header& h) : 
        PositionCommand(h)
    {
    }

    MultiplyPosition⁴::MultiplyPosition⁴(const Header& h, const Vector4D& v) : 
        PositionCommand(h), m_δ(v)
    {
    }

    MultiplyPosition⁴::MultiplyPosition⁴(const MultiplyPosition⁴& cp, const Header& h) : 
        PositionCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition⁴::~MultiplyPosition⁴()
    {
    }

    PostCPtr    MultiplyPosition⁴::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition⁴(*this, h);
    }
    
    void MultiplyPosition⁴::init_info()
    {
        auto w = writer<MultiplyPosition⁴>();
        w.description("Multiply Position Command");
        w.property("δw", &MultiplyPosition⁴::δw).tag(kTag_Log);
        w.property("δx", &MultiplyPosition⁴::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition⁴::δy).tag(kTag_Log);
        w.property("δz", &MultiplyPosition⁴::δz).tag(kTag_Log);
        w.property("δ", &MultiplyPosition⁴::m_δ).tag(kTag_Save);
    }
}
