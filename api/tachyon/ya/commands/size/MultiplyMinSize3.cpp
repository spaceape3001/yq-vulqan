////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/MultiplyMinSize3.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize³)

namespace yq::tachyon {
    MultiplyMinSize³::MultiplyMinSize³(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSize³::MultiplyMinSize³(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMinSize³::MultiplyMinSize³(const MultiplyMinSize³& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize³::~MultiplyMinSize³()
    {
    }

    PostCPtr    MultiplyMinSize³::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize³(*this, h);
    }
    
    void MultiplyMinSize³::init_info()
    {
        auto w = writer<MultiplyMinSize³>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSize³::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMinSize³::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMinSize³::δz).tag(kTag_Log);
        w.property("δ", &MultiplyMinSize³::m_δ).tag(kTag_Save);
    }
}
