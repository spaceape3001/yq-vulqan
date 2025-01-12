////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetMaxSize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize¹)

namespace yq::tachyon {
    SetMaxSize¹::SetMaxSize¹(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetMaxSize¹::SetMaxSize¹(const Header& h, const Size1D& v) : 
        SpatialCommand(h), m_size(v)
    {
    }

    SetMaxSize¹::SetMaxSize¹(const SetMaxSize¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize¹::~SetMaxSize¹()
    {
    }

    PostCPtr    SetMaxSize¹::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize¹(*this, h);
    }
    
    void SetMaxSize¹::init_info()
    {
        auto w = writer<SetMaxSize¹>();
        w.description("SetMax Size Command in 1D");
        w.property("x", &SetMaxSize¹::x).tag(kTag_Log);
        w.property("size", &SetMaxSize¹::m_size).tag(kTag_Save);
    }
}
