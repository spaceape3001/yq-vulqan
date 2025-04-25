////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplyMinSize4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize⁴)

namespace yq::tachyon {
    MultiplyMinSize⁴::MultiplyMinSize⁴(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize⁴::MultiplyMinSize⁴(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize⁴::MultiplyMinSize⁴(const MultiplyMinSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize⁴::~MultiplyMinSize⁴()
    {
    }

    PostCPtr    MultiplyMinSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize⁴(*this, h);
    }
    
    void MultiplyMinSize⁴::init_info()
    {
        auto w = writer<MultiplyMinSize⁴>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize⁴::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize⁴::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMinSize⁴::δz).tag(kTag_Log);
        w.property("δw", &MultiplyMinSize⁴::δw).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize⁴::m_δ).tag(kTag_Save);
    }
}
