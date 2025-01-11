////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyPositionX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionˣ)

namespace yq::tachyon {
    MultiplyPositionˣ::MultiplyPositionˣ(const Header&h) : 
        SpatialCommand(h)
    {
    }

    MultiplyPositionˣ::MultiplyPositionˣ(const Header&h, double x) : 
        SpatialCommand(h), m_δx(x)
    {
    }

    MultiplyPositionˣ::MultiplyPositionˣ(const MultiplyPositionˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyPositionˣ::~MultiplyPositionˣ()
    {
    }
    
    PostCPtr    MultiplyPositionˣ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionˣ(*this, h);
    }

    void MultiplyPositionˣ::init_info()
    {
        auto w = writer<MultiplyPositionˣ>();
        w.description("Multiply Position Command");
        w.property("δx", &MultiplyPositionˣ::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
