////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/widgets/Scene3Widget.hpp>

using namespace yq;
using namespace yq::tachyon;

class ScenePane : public Scene³Widget {
    YQ_TACHYON_DECLARE(ScenePane, Scene³Widget)
public:

    ScenePane();
    ~ScenePane();
    
    static void init_info();
};
