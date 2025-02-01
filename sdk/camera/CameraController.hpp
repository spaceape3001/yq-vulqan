////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Controller.hpp>

namespace yq::tachyon {
    class KeyPressEvent;
}

class CameraController : public yq::tachyon::Controller {
    YQ_TACHYON_DECLARE(CameraController, yq::tachyon::Controller)
public:

    struct Param {
        yq::tachyon::TypedID    camera;
        yq::tachyon::TypedID    listen;
    };

    CameraController(const Param&p={});
    ~CameraController();
    
    yq::tachyon::Execution  setup(const yq::tachyon::Context&) override;
    
    static void init_info();
    
private:
    yq::tachyon::TypedID    m_camera;
    yq::tachyon::TypedID    m_listen;
    bool                    m_init = false;
    
    void on_key_press(const yq::tachyon::KeyPressEvent& evt);
};
