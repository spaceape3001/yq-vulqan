////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetMaxSizeZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeᶻ)

namespace yq::tachyon {
    SetMaxSizeᶻ::SetMaxSizeᶻ(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetMaxSizeᶻ::SetMaxSizeᶻ(const Header& h, double v) : 
        SpatialCommand(h), m_z(v)
    {
    }

    SetMaxSizeᶻ::SetMaxSizeᶻ(const SetMaxSizeᶻ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMaxSizeᶻ::~SetMaxSizeᶻ()
    {
    }

    PostCPtr    SetMaxSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeᶻ(*this, h);
    }
    
    void SetMaxSizeᶻ::init_info()
    {
        auto w = writer<SetMaxSizeᶻ>();
        w.description("SetMax Size Command in Z");
        w.property("z", &SetMaxSizeᶻ::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
