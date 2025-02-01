////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/scenes/SimpleScene3.hpp>

class CameraScene : public yq::tachyon::SimpleScene³ {
    YQ_TACHYON_DECLARE(CameraScene, yq::tachyon::SimpleScene³)
public:

    CameraScene();
    ~CameraScene();
    
    yq::tachyon::Execution  setup(const yq::tachyon::Context&) override;
    
    static void init_info();
    
private:
    bool    m_init = false;
};
