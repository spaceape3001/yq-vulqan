////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/aabb/SetAABB2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetAABB²)

namespace yq::tachyon {
    SetAABB²::SetAABB²(const Header& h, const AxBox2D& v) : 
        AABBCommand(h), m_aabb(v)
    {
    }
    
    SetAABB²::SetAABB²(const SetAABB²& cp, const Header& h) : 
        AABBCommand(cp, h), m_aabb(cp.m_aabb)
    {
    }

    SetAABB²::~SetAABB²()
    {
    }
    
    PostCPtr    SetAABB²::clone(rebind_k, const Header&h) const 
    {
        return new SetAABB²(*this, h);
    }

    void SetAABB²::init_info()
    {
        auto w = writer<SetAABB²>();
        w.description("Set AABB Command");
        w.property("lx", &SetAABB²::lx);
        w.property("ly", &SetAABB²::ly);
        w.property("hx", &SetAABB²::hx);
        w.property("hy", &SetAABB²::hy);
    }
}
