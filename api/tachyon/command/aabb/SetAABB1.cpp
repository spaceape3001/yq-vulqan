////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/aabb/SetAABB1.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetAABB¹)

namespace yq::tachyon {
    SetAABB¹::SetAABB¹(const Header& h, const AxBox1D& v) : 
        AABBCommand(h), m_aabb(v)
    {
    }
    
    SetAABB¹::SetAABB¹(const SetAABB¹& cp, const Header& h) : 
        AABBCommand(cp, h), m_aabb(cp.m_aabb)
    {
    }

    SetAABB¹::~SetAABB¹()
    {
    }
    
    PostCPtr    SetAABB¹::clone(rebind_k, const Header&h) const 
    {
        return new SetAABB¹(*this, h);
    }

    void SetAABB¹::init_info()
    {
        auto w = writer<SetAABB¹>();
        w.description("Set AABB Command");
        w.property("lx", &SetAABB¹::lx).tag(kTag_Log);
        w.property("hx", &SetAABB¹::hx).tag(kTag_Log);
        w.property("aabb", &SetAABB¹::m_aabb).tag(kTag_Save);
    }
}
