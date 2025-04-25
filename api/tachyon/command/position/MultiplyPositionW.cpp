////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MultiplyPositionW.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionʷ)

namespace yq::tachyon {
    MultiplyPositionʷ::MultiplyPositionʷ(const Header&h) : 
        PositionCommand(h)
    {
    }

    MultiplyPositionʷ::MultiplyPositionʷ(const Header&h, double w) : 
        PositionCommand(h), m_δw(w)
    {
    }

    MultiplyPositionʷ::MultiplyPositionʷ(const MultiplyPositionʷ& cp, const Header& h) : 
        PositionCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyPositionʷ::~MultiplyPositionʷ()
    {
    }
    
    PostCPtr    MultiplyPositionʷ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionʷ(*this, h);
    }

    void MultiplyPositionʷ::init_info()
    {
        auto w = writer<MultiplyPositionʷ>();
        w.description("Multiply Position Command");
        w.property("δw", &MultiplyPositionʷ::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
