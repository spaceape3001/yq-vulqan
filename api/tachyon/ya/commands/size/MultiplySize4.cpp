////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplySize4.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize⁴)

namespace yq::tachyon {
    MultiplySize⁴::MultiplySize⁴(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize⁴::MultiplySize⁴(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize⁴::MultiplySize⁴(const MultiplySize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize⁴::~MultiplySize⁴()
    {
    }

    PostCPtr    MultiplySize⁴::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize⁴(*this, h);
    }
    
    void MultiplySize⁴::init_info()
    {
        auto w = writer<MultiplySize⁴>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize⁴::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize⁴::δy).tag(kTag_Log);
        w.property("δz", &MultiplySize⁴::δz).tag(kTag_Log);
        w.property("δw", &MultiplySize⁴::δw).tag(kTag_Log);
        w.property("δ", &MultiplySize⁴::m_δ).tag(kTag_Save);
    }
}
