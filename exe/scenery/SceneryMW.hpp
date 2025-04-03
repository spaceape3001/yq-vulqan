////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/widgets/AppWidget.hpp>

namespace yq::tachyon {
    class OpenFileRequest;
    class SaveFileRequest;
}

using namespace yq;
using namespace yq::tachyon;

class SceneryMW : public AppWidget {
    YQ_TACHYON_DECLARE(SceneryMW, AppWidget)
public:

    SceneryMW();
    ~SceneryMW();
    
    bool    menubar(enabled_k) const override { return true; }
    void    menubar(ViContext&) override;
    void    content(ViContext&) override;

    static void init_info();
};
