////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMinSize2.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize²)

namespace yq::tachyon {
    MultiplyMinSize²::MultiplyMinSize²(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize²::MultiplyMinSize²(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize²::MultiplyMinSize²(const MultiplyMinSize²& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize²::~MultiplyMinSize²()
    {
    }

    PostCPtr    MultiplyMinSize²::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize²(*this, h);
    }
    
    void MultiplyMinSize²::init_info()
    {
        auto w = writer<MultiplyMinSize²>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize²::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize²::δy).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize²::m_δ).tag(kTag_Save);
    }
}
