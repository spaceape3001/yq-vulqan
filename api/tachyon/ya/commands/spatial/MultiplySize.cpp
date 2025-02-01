////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplySize.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySize)

namespace yq::tachyon {
    MultiplySize::MultiplySize(const Header&h, double f) : 
        SpatialCommand(h), m_δ(f)
    {
    }

    MultiplySize::MultiplySize(const MultiplySize& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplySize::MultiplySize(const Header&h) : SpatialCommand(h)
    {
    }

    MultiplySize::~MultiplySize()
    {
    }
    
    PostCPtr    MultiplySize::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySize(*this, h);
    }

    void MultiplySize::init_info()
    {
        auto w = writer<MultiplySize>();
        w.description("Multiply Size Command");
        w.property("δ", &MultiplySize::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
