////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetMinSize3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize³)

namespace yq::tachyon {
    SetMinSize³::SetMinSize³(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetMinSize³::SetMinSize³(const Header& h, const Size3D& v) : 
        SpatialCommand(h), m_size(v)
    {
    }

    SetMinSize³::SetMinSize³(const SetMinSize³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize³::~SetMinSize³()
    {
    }

    PostCPtr    SetMinSize³::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize³(*this, h);
    }
    
    void SetMinSize³::init_info()
    {
        auto w = writer<SetMinSize³>();
        w.description("SetMin Size Command in 3D");
        w.property("x", &SetMinSize³::x).tag(kTag_Log);
        w.property("y", &SetMinSize³::y).tag(kTag_Log);
        w.property("z", &SetMinSize³::z).tag(kTag_Log);
        w.property("size", &SetMinSize³::m_size).tag(kTag_Save);
    }
}
