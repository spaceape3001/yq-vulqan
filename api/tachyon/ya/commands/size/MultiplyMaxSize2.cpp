////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplyMaxSize2.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize²)

namespace yq::tachyon {
    MultiplyMaxSize²::MultiplyMaxSize²(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize²::MultiplyMaxSize²(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize²::MultiplyMaxSize²(const MultiplyMaxSize²& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize²::~MultiplyMaxSize²()
    {
    }

    PostCPtr    MultiplyMaxSize²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize²(*this, h);
    }
    
    void MultiplyMaxSize²::init_info()
    {
        auto w = writer<MultiplyMaxSize²>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize²::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize²::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize²::m_δ).tag(kTag_Save);
    }
}
