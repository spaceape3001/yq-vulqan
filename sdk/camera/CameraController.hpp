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

using namespace yq;
using namespace yq::tachyon;

class CameraController : public Controller {
    YQ_TACHYON_DECLARE(CameraController, Controller)
public:

    CameraController(TypedID);
    ~CameraController();
    
    static void init_info();
    
private:
    TypedID    m_camera;
    
    void on_key_press(const KeyPressEvent& evt);
};
