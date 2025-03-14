////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

using namespace yq;
using namespace yq::tachyon;

class MainWidget : public Widget {
    YQ_TACHYON_DECLARE(MainWidget, Widget)
public:

    MainWidget();
    ~MainWidget();
    
    static void init_info();
};
