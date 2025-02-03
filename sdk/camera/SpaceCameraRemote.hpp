////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    class Orientation³Control;
}

using namespace yq;
using namespace yq::tachyon;

/*! \brief Meant to be remote control to a space camera
*/
class SpaceCameraRemote : public Widget {
    YQ_TACHYON_DECLARE(SpaceCameraRemote, Widget)
public:

    SpaceCameraRemote(TypedID);
    ~SpaceCameraRemote();
    
    Execution setup(const Context&) override;
    void    imgui(ViContext&) override;
    
    static void init_info();

private:
    TypedID                 m_camera;
    TypedID                 m_spatial;
    TypedID                 m_position;
    Orientation³Control*    m_orientation = nullptr;
    bool                    m_init  = false;
};

