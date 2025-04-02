////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/widgets/AppWidget.hpp>

using namespace yq;
using namespace yq::tachyon;

class SceneryMW : public AppWidget {
    YQ_TACHYON_DECLARE(SceneryMW, AppWidget)
public:

    SceneryMW();
    ~SceneryMW();
    
    bool    menubar(enabled_k) const override { return true; }
    void    menubar(ViContext&) override;

    static void init_info();
};
