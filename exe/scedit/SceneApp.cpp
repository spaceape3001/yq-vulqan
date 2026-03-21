////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneApp.hpp"
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(SceneApp)

SceneApp::SceneApp(int&argc, char* argv[], yq::tachyon::Application& app) : YAppThread(argc, argv, app)
{
}

SceneApp::~SceneApp()
{
}
