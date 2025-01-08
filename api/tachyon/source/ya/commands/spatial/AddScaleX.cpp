////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddScaleX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScaleˣ)

namespace yq::tachyon {
    AddScaleˣ::AddScaleˣ(const Header&h, double x) : 
        SpatialCommand(h), m_x(x)
    {
    }

    AddScaleˣ::AddScaleˣ(const AddScaleˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    AddScaleˣ::~AddScaleˣ()
    {
    }
    
    PostCPtr    AddScaleˣ::clone(rebind_k, const Header&h) const 
    {
        return new AddScaleˣ(*this, h);
    }

    void AddScaleˣ::init_info()
    {
        auto w = writer<AddScaleˣ>();
        w.description("Add Scale Command");
        w.property("x", &AddScaleˣ::x);
    }
}
