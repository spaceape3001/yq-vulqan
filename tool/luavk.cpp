////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/process/PluginLoader.hpp>

#include <tachyon/MyImGui.hpp>
#include <tachyon/application.hpp>
#include <tachyon/viewer.hpp>
#include <tachyon/widget.hpp>

#include <tachyon/api/Tachyon.hxx>
#include <tachyon/ui/UIWriters.hxx>
#include <ImGuiFileDialog.h>

using namespace yq;
using namespace yq::tachyon;

class LuaWin : public Widget {
    YQ_TACHYON_DECLARE(LuaWin, Widget)
public:

    enum class FileMode {
        None
    };
    
    FileMode        m_fileMode = FileMode::None;
    
    LuaWin()
    {
    }
    
    ~LuaWin()
    {
    }

    void    imgui(ViContext&u) 
    {
        Widget::imgui(UI,u);
        

        if(m_fileMode != FileMode::None){
            ImVec2  minSize = { (float)(0.5 * width()), (float)(0.5 * height()) };
            if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoCollapse, minSize)) {
                if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
                    std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                    
                    switch(m_fileMode){
                    case FileMode::None:
                        break;
                    }
                }
                ImGuiFileDialog::Instance()->Close();
            }
        }
    }
    
    ////////////////////////////////////

    static void init_meta()
    {
        auto w = writer<LuaWin>();
        w.description("Lua Window");
        auto app        = w.imgui(UI, APP);
        
        auto mmb        = app.menubar(MAIN);
        mmb.uid("mmb");
        
        auto file       = mmb.menu("Lua");
        file.menuitem("Run...");
    }
};

YQ_TACHYON_IMPLEMENT(LuaWin);

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    
    aci.thread.sim          = true;
    aci.view.clear          = { 0.005f, 0.005f, 0.005f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    aci.view.size           = { 1920, 1080 };
    aci.view.title          = "LUA!";

    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    load_plugin_dir("plugin/lua");
    Meta::init();

    app.start();

    LuaWin* w   = LuaWin::create<LuaWin>();
    app.run(w);
    return 0;
}
