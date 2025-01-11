////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyPositionZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionᶻ)

namespace yq::tachyon {
    MultiplyPositionᶻ::MultiplyPositionᶻ(const Header&h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyPositionᶻ::MultiplyPositionᶻ(const Header&h, double z) : 
        SpatialCommand(h), m_δz(z)
    {
    }
    
    MultiplyPositionᶻ::MultiplyPositionᶻ(const MultiplyPositionᶻ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δz(cp.m_δz)
    {
    }

    MultiplyPositionᶻ::~MultiplyPositionᶻ()
    {
    }

    PostCPtr    MultiplyPositionᶻ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionᶻ(*this, h);
    }
    
    void MultiplyPositionᶻ::init_info()
    {
        auto w = writer<MultiplyPositionᶻ>();
        w.description("Multiply Position Command");
        w.property("δz", &MultiplyPositionᶻ::m_δz).tag(kTag_Log).tag(kTag_Save);
    }
}
