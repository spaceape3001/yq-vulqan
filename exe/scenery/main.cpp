////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"

#include <tachyon/application.hpp>
#include <tachyon/io/FileIOManager.hpp>
#include <yq/asset/Asset.hpp>
#include <yq/core/Logging.hpp>
#include <yq/file/FileResolver.hpp>

TypedID     gFileIO;

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.io           = true;
    aci.thread.sim          = true;
    aci.view.title          = "Scenery Editor";
    aci.view.size           = { 1920, 1080 };
    aci.view.clear          = { 0.0f, 0.0f, 0.0f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    
    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    
    for(const std::filesystem::path& pth : Asset::resolver().paths())
        yInfo() << "asset path> " << pth;
    
    app.start();
    
    gFileIO             = Tachyon::create_on<FileIOManager>(IO)->typed_id();
    
    SceneEditor* w      = Widget::create<SceneEditor>();
    app.run(w);
    return 0;
}

