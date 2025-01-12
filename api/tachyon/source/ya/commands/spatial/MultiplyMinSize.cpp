////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMinSize.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSize)

namespace yq::tachyon {
    MultiplyMinSize::MultiplyMinSize(const Header&h, double f) : 
        SpatialCommand(h), m_δ(f)
    {
    }

    MultiplyMinSize::MultiplyMinSize(const MultiplyMinSize& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMinSize::MultiplyMinSize(const Header&h) : SpatialCommand(h)
    {
    }

    MultiplyMinSize::~MultiplyMinSize()
    {
    }
    
    PostCPtr    MultiplyMinSize::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSize(*this, h);
    }

    void MultiplyMinSize::init_info()
    {
        auto w = writer<MultiplyMinSize>();
        w.description("MultiplyMin Size Command");
        w.property("δ", &MultiplyMinSize::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
