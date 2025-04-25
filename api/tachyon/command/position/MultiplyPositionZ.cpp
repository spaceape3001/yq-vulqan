////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPositionZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionᶻ)

namespace yq::tachyon {
    MultiplyPositionᶻ::MultiplyPositionᶻ(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MultiplyPositionᶻ::MultiplyPositionᶻ(const Header&h, double z) : 
        PositionCommand(h), m_δz(z)
    {
    }
    
    MultiplyPositionᶻ::MultiplyPositionᶻ(const MultiplyPositionᶻ& cp, const Header& h) : 
        PositionCommand(cp, h), m_δz(cp.m_δz)
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
