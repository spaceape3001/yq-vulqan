////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YMain.hpp>

using namespace yq;
using namespace yq::tachyon;

class MainWindow : public YMain {
    YQ_TACHYON_DECLARE(MainWindow, YMain)
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    
    static void init_meta();
};
