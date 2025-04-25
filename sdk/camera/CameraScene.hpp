////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/SimpleScene3.hpp>

using namespace yq;
using namespace yq::tachyon;

class CameraScene : public yq::tachyon::SimpleScene³ {
    YQ_TACHYON_DECLARE(CameraScene, SimpleScene³)
public:

    CameraScene();
    ~CameraScene();
    
    Execution  setup(const Context&) override;
    
    static void init_info();
    
private:
    bool    m_init = false;
};
