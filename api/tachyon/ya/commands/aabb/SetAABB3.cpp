////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/aabb/SetAABB3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetAABB³)

namespace yq::tachyon {
    SetAABB³::SetAABB³(const Header& h, const AxBox3D& v) : 
        AABBCommand(h), m_aabb(v)
    {
    }
    
    SetAABB³::SetAABB³(const SetAABB³& cp, const Header& h) : 
        AABBCommand(cp, h), m_aabb(cp.m_aabb)
    {
    }

    SetAABB³::~SetAABB³()
    {
    }
    
    PostCPtr    SetAABB³::clone(rebind_k, const Header&h) const 
    {
        return new SetAABB³(*this, h);
    }

    void SetAABB³::init_info()
    {
        auto w = writer<SetAABB³>();
        w.description("Set AABB Command");
        w.property("lx", &SetAABB³::lx);
        w.property("ly", &SetAABB³::ly);
        w.property("lz", &SetAABB³::lz);
        w.property("hx", &SetAABB³::hx);
        w.property("hy", &SetAABB³::hy);
        w.property("hz", &SetAABB³::hz);
    }
}
