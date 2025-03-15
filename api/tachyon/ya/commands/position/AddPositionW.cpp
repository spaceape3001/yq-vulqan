////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/AddPositionW.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʷ)

namespace yq::tachyon {
    AddPositionʷ::AddPositionʷ(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʷ::AddPositionʷ(const Header&h, double Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    AddPositionʷ::AddPositionʷ(const AddPositionʷ& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    AddPositionʷ::~AddPositionʷ()
    {
    }
    
    PostCPtr    AddPositionʷ::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionʷ(*this, h);
    }

    void AddPositionʷ::init_info()
    {
        auto w = writer<AddPositionʷ>();
        w.description("Position AddPosition Command in X");
        w.property("Δw", &AddPositionʷ::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
