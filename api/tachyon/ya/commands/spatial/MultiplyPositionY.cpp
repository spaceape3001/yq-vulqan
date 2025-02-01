////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyPositionY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionʸ)

namespace yq::tachyon {
    MultiplyPositionʸ::MultiplyPositionʸ(const Header& h) : 
        SpatialCommand(h)
    {
    }
    
    MultiplyPositionʸ::MultiplyPositionʸ(const Header& h, double y) : 
        SpatialCommand(h), m_δy(y)
    {
    }

    MultiplyPositionʸ::MultiplyPositionʸ(const MultiplyPositionʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyPositionʸ::~MultiplyPositionʸ()
    {
    }

    PostCPtr    MultiplyPositionʸ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionʸ(*this, h);
    }
    
    void MultiplyPositionʸ::init_info()
    {
        auto w = writer<MultiplyPositionʸ>();
        w.description("Multiply Position Command");
        w.property("δy", &MultiplyPositionʸ::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
