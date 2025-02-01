////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyMaxSize.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMaxSize)

namespace yq::tachyon {
    MultiplyMaxSize::MultiplyMaxSize(const Header&h, double f) : 
        SpatialCommand(h), m_δ(f)
    {
    }

    MultiplyMaxSize::MultiplyMaxSize(const MultiplyMaxSize& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δ(cp.m_δ)
    {
    }
    
    MultiplyMaxSize::MultiplyMaxSize(const Header&h) : SpatialCommand(h)
    {
    }

    MultiplyMaxSize::~MultiplyMaxSize()
    {
    }
    
    PostCPtr    MultiplyMaxSize::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMaxSize(*this, h);
    }

    void MultiplyMaxSize::init_info()
    {
        auto w = writer<MultiplyMaxSize>();
        w.description("MultiplyMax Size Command");
        w.property("δ", &MultiplyMaxSize::m_δ).tag(kTag_Log).tag(kTag_Save);
    }
}
