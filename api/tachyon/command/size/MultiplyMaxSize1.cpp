////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSize1.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize¹)

namespace yq::tachyon {
    MultiplyMaxSize¹::MultiplyMaxSize¹(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMaxSize¹::MultiplyMaxSize¹(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize¹::MultiplyMaxSize¹(const MultiplyMaxSize¹& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }

    MultiplyMaxSize¹::~MultiplyMaxSize¹()
    {
    }
    
    PostCPtr    MultiplyMaxSize¹::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize¹(*this, h);
    }

    void MultiplyMaxSize¹::init_info()
    {
        auto w = writer<MultiplyMaxSize¹>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize¹::δx).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize¹::m_δ).tag(kTag_Save);
    }
}
