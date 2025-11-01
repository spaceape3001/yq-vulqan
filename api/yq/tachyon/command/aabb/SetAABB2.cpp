////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/aabb/SetAABB2.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

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

    void SetAABB²::init_meta()
    {
        auto w = writer<SetAABB²>();
        w.description("Set AABB Command");
        w.property("lx", &SetAABB²::lx).tag(kTag_Log);
        w.property("ly", &SetAABB²::ly).tag(kTag_Log);
        w.property("hx", &SetAABB²::hx).tag(kTag_Log);
        w.property("hy", &SetAABB²::hy).tag(kTag_Log);
        w.property("aabb", &SetAABB²::m_aabb).tag(kTag_Save);
    }
}
