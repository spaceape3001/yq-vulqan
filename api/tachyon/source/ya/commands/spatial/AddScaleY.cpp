////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScaleY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleʸ)

namespace yq::tachyon {
    AddScaleʸ::AddScaleʸ(const Header& h, double y) : 
        SpatialCommand(h), m_y(y)
    {
    }
    
    AddScaleʸ::AddScaleʸ(const AddScaleʸ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_y(cp.m_y)
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
        w.description("Add Scale Command");
        w.property("y", &AddScaleʸ::y);
    }
}
