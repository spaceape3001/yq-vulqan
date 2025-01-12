////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMinSizeX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeˣ)

namespace yq::tachyon {
    MultiplyMinSizeˣ::MultiplyMinSizeˣ(const Header&h) : 
        SpatialCommand(h)
    {
    }

    MultiplyMinSizeˣ::MultiplyMinSizeˣ(const Header&h, double x) : 
        SpatialCommand(h), m_δx(x)
    {
    }

    MultiplyMinSizeˣ::MultiplyMinSizeˣ(const MultiplyMinSizeˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyMinSizeˣ::~MultiplyMinSizeˣ()
    {
    }
    
    PostCPtr    MultiplyMinSizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeˣ(*this, h);
    }

    void MultiplyMinSizeˣ::init_info()
    {
        auto w = writer<MultiplyMinSizeˣ>();
        w.description("MultiplyMin Size Command");
        w.property("δx", &MultiplyMinSizeˣ::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
