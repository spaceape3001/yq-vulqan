////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddPositionY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʸ)

namespace yq::tachyon {
    AddPositionʸ::AddPositionʸ(const Header&h) : 
        SpatialCommand(h)
    {
    }

    AddPositionʸ::AddPositionʸ(const Header&h, double Δy) : 
        SpatialCommand(h), m_Δy(Δy)
    {
    }

    AddPositionʸ::AddPositionʸ(const AddPositionʸ& cp, const Header&h) : 
        SpatialCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    AddPositionʸ::~AddPositionʸ()
    {
    }
    
    PostCPtr    AddPositionʸ::clone(rebind_k, const Header& h) const 
    {
        return new AddPositionʸ(*this, h);
    }

    void AddPositionʸ::init_info()
    {
        auto w = writer<AddPositionʸ>();
        w.description("Position AddPosition Command in Y");
        w.property("Δy", &AddPositionʸ::Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
