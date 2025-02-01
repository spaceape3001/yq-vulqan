////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplySizeX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeˣ)

namespace yq::tachyon {
    MultiplySizeˣ::MultiplySizeˣ(const Header&h) : 
        SpatialCommand(h)
    {
    }

    MultiplySizeˣ::MultiplySizeˣ(const Header&h, double x) : 
        SpatialCommand(h), m_δx(x)
    {
    }

    MultiplySizeˣ::MultiplySizeˣ(const MultiplySizeˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplySizeˣ::~MultiplySizeˣ()
    {
    }
    
    PostCPtr    MultiplySizeˣ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeˣ(*this, h);
    }

    void MultiplySizeˣ::init_info()
    {
        auto w = writer<MultiplySizeˣ>();
        w.description("Multiply Size Command");
        w.property("δx", &MultiplySizeˣ::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
