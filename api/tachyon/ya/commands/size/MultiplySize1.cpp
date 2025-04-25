////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplySize1.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize¹)

namespace yq::tachyon {
    MultiplySize¹::MultiplySize¹(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySize¹::MultiplySize¹(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize¹::MultiplySize¹(const MultiplySize¹& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
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
