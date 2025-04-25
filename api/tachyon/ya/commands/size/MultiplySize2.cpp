////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplySize2.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize²)

namespace yq::tachyon {
    MultiplySize²::MultiplySize²(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplySize²::MultiplySize²(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplySize²::MultiplySize²(const MultiplySize²& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize²::~MultiplySize²()
    {
    }

    PostCPtr    MultiplySize²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize²(*this, h);
    }
    
    void MultiplySize²::init_info()
    {
        auto w = writer<MultiplySize²>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize²::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize²::δy).tag(kTag_Log);
        w.property("δ", &MultiplySize²::m_δ).tag(kTag_Save);
    }
}
