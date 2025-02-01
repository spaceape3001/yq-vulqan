////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyPosition3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPosition³)

namespace yq::tachyon {
    MultiplyPosition³::MultiplyPosition³(const Header& h) : 
        SpatialCommand(h)
    {
    }

    MultiplyPosition³::MultiplyPosition³(const Header& h, const Vector3D& v) : 
        SpatialCommand(h), m_δ(v)
    {
    }

    MultiplyPosition³::MultiplyPosition³(const MultiplyPosition³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyPosition³::~MultiplyPosition³()
    {
    }

    PostCPtr    MultiplyPosition³::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPosition³(*this, h);
    }
    
    void MultiplyPosition³::init_info()
    {
        auto w = writer<MultiplyPosition³>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPosition³::δx).tag(kTag_Log);
        w.property("δy", &MultiplyPosition³::δy).tag(kTag_Log);
        w.property("δz", &MultiplyPosition³::δz).tag(kTag_Log);
        w.property("δ", &MultiplyPosition³::m_δ).tag(kTag_Save);
    }
}
