////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    class OpenFileRequest;
    class SaveFileRequest;
}

using namespace yq;
using namespace yq::tachyon;

class SceneryMW : public Widget {
    YQ_TACHYON_DECLARE(SceneryMW, Widget)
public:

    SceneryMW();
    ~SceneryMW();
    
    //bool    menubar(enabled_k) const override { return true; }
    //void    menubar(ViContext&) override;
    using Widget::imgui;
    void    imgui(ViContext&) override;
    

    static void init_info();
};
