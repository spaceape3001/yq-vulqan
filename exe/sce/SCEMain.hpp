////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YMain.hpp>

using namespace yq;
using namespace yq::tachyon;

class SCEMain : public YMain {
    YQ_TACHYON_DECLARE(SCEMain, YMain)
    Q_OBJECT
public:

    SCEMain();
    ~SCEMain();
    
    static void init_meta();
};
