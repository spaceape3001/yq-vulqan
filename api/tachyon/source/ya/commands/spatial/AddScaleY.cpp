////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScaleY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleʸ)

namespace yq::tachyon {
    AddScaleʸ::AddScaleʸ(const Header& h) : 
        SpatialCommand(h)
    {
    }

    AddScaleʸ::AddScaleʸ(const Header& h, double y) : 
        SpatialCommand(h), m_Δy(y)
    {
    }
    
    AddScaleʸ::AddScaleʸ(const AddScaleʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddScaleʸ::~AddScaleʸ()
    {
    }

    PostCPtr    AddScaleʸ::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleʸ(*this, h);
    }
    
    void AddScaleʸ::init_info()
    {
        auto w = writer<AddScaleʸ>();
        w.description("Add Scale Command in Y");
        w.property("Δy", &AddScaleʸ::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
