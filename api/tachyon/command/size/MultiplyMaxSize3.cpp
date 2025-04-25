////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMaxSize3.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize³)

namespace yq::tachyon {
    MultiplyMaxSize³::MultiplyMaxSize³(const Header& h) : 
        SizeCommand(h)
    {
    }

    MultiplyMaxSize³::MultiplyMaxSize³(const Header& h, const Vector3D& v) : 
        SizeCommand(h), m_δ(v)
    {
    }

    MultiplyMaxSize³::MultiplyMaxSize³(const MultiplyMaxSize³& cp, const Header& h) : 
        SizeCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize³::~MultiplyMaxSize³()
    {
    }

    PostCPtr    MultiplyMaxSize³::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize³(*this, h);
    }
    
    void MultiplyMaxSize³::init_info()
    {
        auto w = writer<MultiplyMaxSize³>();
        w.description("MultiplyMax Size Command");
        w.property("δx", &MultiplyMaxSize³::δx).tag(kTag_Log);
        w.property("δy", &MultiplyMaxSize³::δy).tag(kTag_Log);
        w.property("δz", &MultiplyMaxSize³::δz).tag(kTag_Log);
        w.property("δ", &MultiplyMaxSize³::m_δ).tag(kTag_Save);
    }
}
