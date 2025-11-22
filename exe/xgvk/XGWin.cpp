////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGWin.hpp"
#include "PalettePanel.hpp"
#include "ViewPanel.hpp"

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/xgvk/ui/XGView.hpp>
#include <yq/xgvk/ui/XGViewWriter.hpp>
#include <ImGuiFileDialog.h>

YQ_TACHYON_IMPLEMENT(XGWin)

using namespace yq::tachyon;
using namespace yq::xg;

void XGWin::init_meta()
{
    auto w = writer<XGWin>();

    auto app        = w.imgui(UI, APP);
    auto mmb        = app.menubar(MAIN);
    
    auto ppw         = app.make<PalettePanel>();
    ppw.uid("PalettePanel");
    ppw.button("Hello, this is the palette panel");
    
    auto vp          = app.make<ViewPanel>();
    vp.flag(SET, UIFlag::NoDecoration);
    auto xgv = vp.make<XGView>();
    xgv.uid("XGView");
    
    auto ttb        = app.toolbar(Cardinal::SSE, "##Tools");
    ttb.button("Tools");

    
    auto file       = mmb.menu("File");
    auto edit       = mmb.menu("Edit");
    auto view       = mmb.menu("View");
    
    file.menuitem("Open").action(&XGWin::cmd_file_open);
    file.menuitem("Save").action(&XGWin::cmd_file_save);
    file.menuitem("Save As").action(&XGWin::cmd_file_saveas);

    view.checkbox("Tools").action(VISIBLE, ttb);
    view.checkbox("Palette").action(VISIBLE, ppw);
}

XGWin::XGWin(XGDocumentPtr dp) : m_document(dp)
{
}

XGWin::~XGWin()
{
}

void XGWin::_open(const std::filesystem::path&)
{
    // TODO
}

void XGWin::_save(const std::filesystem::path&)
{
    // TODO
}

void    XGWin::cmd_file_open()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Open", ".xg", config);        
    m_fileMode  = FileMode::Open;
}

void    XGWin::cmd_file_save()
{
}

void    XGWin::cmd_file_saveas()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    config.flags |= ImGuiFileDialogFlags_ConfirmOverwrite;
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Save", ".xg", config);        
    m_fileMode  = FileMode::Save;
}

void    XGWin::imgui(ViContext&u) 
{
    Widget::imgui(UI,u);

    if(m_fileMode != FileMode::None){
        ImVec2  minSize = { (float)(0.5 * width()), (float)(0.5 * height()) };
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoCollapse, minSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                switch(m_fileMode){
                case FileMode::None:
                    break;
                case FileMode::Open:
                    _open(filePathName);
                    break;
                case FileMode::Save:
                    _save(filePathName);
                    break;
                }
            }
            m_fileMode      = FileMode::None;
            ImGuiFileDialog::Instance()->Close();
        }
    }
}
