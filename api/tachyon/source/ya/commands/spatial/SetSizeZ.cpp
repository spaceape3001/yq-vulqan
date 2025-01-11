////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetSizeZ.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeᶻ)

namespace yq::tachyon {
    SetSizeᶻ::SetSizeᶻ(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetSizeᶻ::SetSizeᶻ(const Header& h, double v) : 
        SpatialCommand(h), m_z(v)
    {
    }

    SetSizeᶻ::SetSizeᶻ(const SetSizeᶻ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetSizeᶻ::~SetSizeᶻ()
    {
    }

    PostCPtr    SetSizeᶻ::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeᶻ(*this, h);
    }
    
    void SetSizeᶻ::init_info()
    {
        auto w = writer<SetSizeᶻ>();
        w.description("Set Size Command in Z");
        w.property("z", &SetSizeᶻ::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
