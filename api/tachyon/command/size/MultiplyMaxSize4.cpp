////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSize4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize⁴)

namespace yq::tachyon {
    MultiplyMaxSize⁴::MultiplyMaxSize⁴(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize⁴::MultiplyMaxSize⁴(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize⁴::MultiplyMaxSize⁴(const MultiplyMaxSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize⁴::~MultiplyMaxSize⁴()
    {
    }

    PostCPtr    MultiplyMaxSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize⁴(*this, h);
    }
    
    void MultiplyMaxSize⁴::init_info()
    {
        auto w = writer<MultiplyMaxSize⁴>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize⁴::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize⁴::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMaxSize⁴::δz).tag(kTag_Log);
        w.property("δw", &MultiplyMaxSize⁴::δw).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize⁴::m_δ).tag(kTag_Save);
    }
}
