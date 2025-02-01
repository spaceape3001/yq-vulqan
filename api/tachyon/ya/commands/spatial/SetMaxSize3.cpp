////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetMaxSize3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize³)

namespace yq::tachyon {
    SetMaxSize³::SetMaxSize³(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetMaxSize³::SetMaxSize³(const Header& h, const Size3D& v) : 
        SpatialCommand(h), m_size(v)
    {
    }

    SetMaxSize³::SetMaxSize³(const SetMaxSize³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize³::~SetMaxSize³()
    {
    }

    PostCPtr    SetMaxSize³::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize³(*this, h);
    }
    
    void SetMaxSize³::init_info()
    {
        auto w = writer<SetMaxSize³>();
        w.description("SetMax Size Command in 3D");
        w.property("x", &SetMaxSize³::x).tag(kTag_Log);
        w.property("y", &SetMaxSize³::y).tag(kTag_Log);
        w.property("z", &SetMaxSize³::z).tag(kTag_Log);
        w.property("size", &SetMaxSize³::m_size).tag(kTag_Save);
    }
}
