////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AFieldOfView.hpp"
#include "AFieldOfViewWriter.hxx"
#include <tachyon/command/camera/SetFOVCommand.hpp>

namespace yq::tachyon {
    AFieldOfView::AFieldOfView() = default;
    AFieldOfView::~AFieldOfView() = default;

    void    AFieldOfView::field_of_view(set_k, unit::Degree v)
    {
        m_fov = v;
        mark();
    }

    void    AFieldOfView::on_set_fov(const SetFOVCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        field_of_view(SET, cmd.fov());
    }
}

