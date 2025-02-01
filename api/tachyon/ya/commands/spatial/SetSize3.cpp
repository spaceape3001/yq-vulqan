////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetSize3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize³)

namespace yq::tachyon {
    SetSize³::SetSize³(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetSize³::SetSize³(const Header& h, const Size3D& v) : 
        SpatialCommand(h), m_size(v)
    {
    }

    SetSize³::SetSize³(const SetSize³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize³::~SetSize³()
    {
    }

    PostCPtr    SetSize³::clone(rebind_k, const Header&h) const 
    {
        return new SetSize³(*this, h);
    }
    
    void SetSize³::init_info()
    {
        auto w = writer<SetSize³>();
        w.description("Set Size Command in 3D");
        w.property("x", &SetSize³::x).tag(kTag_Log);
        w.property("y", &SetSize³::y).tag(kTag_Log);
        w.property("z", &SetSize³::z).tag(kTag_Log);
        w.property("size", &SetSize³::m_size).tag(kTag_Save);
    }
}
