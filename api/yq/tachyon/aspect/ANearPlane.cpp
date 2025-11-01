////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ANearPlane.hpp"
#include "ANearPlaneWriter.hxx"
#include <tachyon/command/camera/SetNearPlaneCommand.hpp>

namespace yq::tachyon {
    ANearPlane::ANearPlane() = default;
    ANearPlane::~ANearPlane() = default;

    void    ANearPlane::near_plane(set_k, double v)
    {
        m_near = v;
        mark();
    }

    void    ANearPlane::on_set_near_plane(const SetNearPlaneCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        near_plane(SET, cmd.near());
    }
}

