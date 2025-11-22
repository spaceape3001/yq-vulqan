////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/scene/SimpleScene.hpp>

using namespace yq;
using namespace yq::tachyon;

class CameraScene : public yq::tachyon::SimpleScene {
    YQ_TACHYON_DECLARE(CameraScene, SimpleScene)
public:

    CameraScene();
    ~CameraScene();
    
    Execution  setup(const Context&) override;
    
    static void init_meta();
    
private:
    bool    m_init = false;
};
