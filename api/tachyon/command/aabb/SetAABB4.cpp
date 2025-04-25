////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/aabb/SetAABB4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetAABB⁴)

namespace yq::tachyon {
    SetAABB⁴::SetAABB⁴(const Header& h, const AxBox4D& v) : 
        AABBCommand(h), m_aabb(v)
    {
    }
    
    SetAABB⁴::SetAABB⁴(const SetAABB⁴& cp, const Header& h) : 
        AABBCommand(cp, h), m_aabb(cp.m_aabb)
    {
    }

    SetAABB⁴::~SetAABB⁴()
    {
    }
    
    PostCPtr    SetAABB⁴::clone(rebind_k, const Header&h) const 
    {
        return new SetAABB⁴(*this, h);
    }

    void SetAABB⁴::init_info()
    {
        auto w = writer<SetAABB⁴>();
        w.description("Set AABB Command");
        w.property("lx", &SetAABB⁴::lx).tag(kTag_Log);
        w.property("ly", &SetAABB⁴::ly).tag(kTag_Log);
        w.property("lz", &SetAABB⁴::lz).tag(kTag_Log);
        w.property("lw", &SetAABB⁴::lw).tag(kTag_Log);
        w.property("hx", &SetAABB⁴::hx).tag(kTag_Log);
        w.property("hy", &SetAABB⁴::hy).tag(kTag_Log);
        w.property("hz", &SetAABB⁴::hz).tag(kTag_Log);
        w.property("hw", &SetAABB⁴::hw).tag(kTag_Log);
        w.property("aabb", &SetAABB⁴::m_aabb).tag(kTag_Save);
    }
}
