////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/scale/MultiplyScale3.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScale³)

namespace yq::tachyon {
    MultiplyScale³::MultiplyScale³(const Header& h) : 
        ScaleCommand(h)
    {
    }

    MultiplyScale³::MultiplyScale³(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_δ(v)
    {
    }

    MultiplyScale³::MultiplyScale³(const MultiplyScale³& cp, const Header& h) : 
        ScaleCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyScale³::~MultiplyScale³()
    {
    }

    PostCPtr    MultiplyScale³::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScale³(*this, h);
    }
    
    void MultiplyScale³::init_info()
    {
        auto w = writer<MultiplyScale³>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScale³::δx).tag(kTag_Log);
        w.property("δy", &MultiplyScale³::δy).tag(kTag_Log);
        w.property("δz", &MultiplyScale³::δz).tag(kTag_Log);
        w.property("δ", &MultiplyScale³::m_δ).tag(kTag_Save);
    }
}
