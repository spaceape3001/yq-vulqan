////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vkqt/app/YAppThread.hpp>

class SceneApp : public yq::tachyon::YAppThread {
    YQ_TACHYON_DECLARE(SceneApp, YAppThread)
    Q_OBJECT
public:
    SceneApp(int&,char* argv[], yq::tachyon::Application&);
    ~SceneApp();
};
