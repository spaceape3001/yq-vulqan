////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddPositionZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionᶻ)

namespace yq::tachyon {
    AddPositionᶻ::AddPositionᶻ(const Header&h) : 
        SpatialCommand(h)
    {
    }
    
    AddPositionᶻ::AddPositionᶻ(const Header&h, double Δz) : 
        SpatialCommand(h), m_Δz(Δz)
    {
    }

    AddPositionᶻ::AddPositionᶻ(const AddPositionᶻ& cp, const Header&h) : 
        SpatialCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddPositionᶻ::~AddPositionᶻ()
    {
    }
    
    PostCPtr    AddPositionᶻ::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionᶻ(*this, h);
    }

    void AddPositionᶻ::init_info()
    {
        auto w = writer<AddPositionᶻ>();
        w.description("Position AddPosition Command in Z");
        w.property("Δz", &AddPositionᶻ::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
