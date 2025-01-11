////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplySize3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize³)

namespace yq::tachyon {
    MultiplySize³::MultiplySize³(const Header& h) : 
        SpatialCommand(h)
    {
    }

    MultiplySize³::MultiplySize³(const Header& h, const Vector3D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplySize³::MultiplySize³(const MultiplySize³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize³::~MultiplySize³()
    {
    }

    PostCPtr    MultiplySize³::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize³(*this, h);
    }
    
    void MultiplySize³::init_info()
    {
        auto w = writer<MultiplySize³>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySize³::δx).tag(kTag_Log);
        w.property("δy", &MultiplySize³::δy).tag(kTag_Log);
        w.property("δz", &MultiplySize³::δz).tag(kTag_Log);
        w.property("δ", &MultiplySize³::m_δ).tag(kTag_Save);
    }
}
