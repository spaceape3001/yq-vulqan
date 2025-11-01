////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AFarPlane.hpp"
#include "AFarPlaneWriter.hxx"
#include <yq/tachyon/command/camera/SetFarPlaneCommand.hpp>

namespace yq::tachyon {
    AFarPlane::AFarPlane() = default;
    AFarPlane::~AFarPlane() = default;

    void    AFarPlane::far_plane(set_k, double v)
    {
        m_far = v;
        mark();
    }

    void    AFarPlane::on_set_far_plane(const SetFarPlaneCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        far_plane(SET, cmd.far());
    }
}

