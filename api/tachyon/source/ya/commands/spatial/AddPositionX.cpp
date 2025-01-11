////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddPositionX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionˣ)

namespace yq::tachyon {
    AddPositionˣ::AddPositionˣ(const Header&h) : 
        SpatialCommand(h)
    {
    }

    AddPositionˣ::AddPositionˣ(const Header&h, double Δx) : 
        SpatialCommand(h), m_Δx(Δx)
    {
    }
    
    AddPositionˣ::AddPositionˣ(const AddPositionˣ& cp, const Header&h) : 
        SpatialCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    AddPositionˣ::~AddPositionˣ()
    {
    }
    
    PostCPtr    AddPositionˣ::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionˣ(*this, h);
    }

    void AddPositionˣ::init_info()
    {
        auto w = writer<AddPositionˣ>();
        w.description("Position AddPosition Command in X");
        w.property("Δx", &AddPositionˣ::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
