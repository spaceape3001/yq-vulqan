////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGWin.hpp"
//#include "PalettePanel.hpp"
//#include "ViewPanel.hpp"

#include <yq/xg/XGElement.hpp>
#include <yq/assetvk/ui/UIBuildableMetaList.hpp>
#include <yq/assetvk/ui/UIPanel.hpp>
#include <yq/assetvk/ui/UIPanelWriter.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/xgvk/ui/XGView.hpp>
#include <yq/xgvk/ui/XGViewWriter.hpp>
#include <ImGuiFileDialog.h>

YQ_TACHYON_IMPLEMENT(XGWin)

using namespace yq;
using namespace yq::tachyon;
using namespace yq::xg;

void XGWin::init_meta()
{
    auto w = writer<XGWin>();

    auto app        = w.imgui(UI, APP);
    auto mmb        = app.menubar(MAIN);
    
    auto ppw         = app.make<UIPanel>("##Pallette");
    {
        ppw.uid("PalettePanel");
        ppw.flag(SET, UIFlag::NoDecoration);    // until min/max work
        //ppw.width(MINIMUM, PIVOT, 0.20);
        //ppw.width(MAXIMUM, PIVOT, 0.80);
        ppw.right(PIVOT, 0.20); //temporary
        auto x = ppw.make<UIBuildableMetaList<xg::XGElement>>();
        x.flag(SET, UIFlag::EmitSignal);
    }

    auto ttb        = app.make<UIPanel>("##Tools");
    {
        ttb.flag(SET, UIFlag::NoDecoration);
        ttb.uid("ToolBar");
        ttb.left("PalettePanel", RIGHT);
        ttb.height(TOOLBAR);
        
        auto h      = ttb.hline();
        h.button("Tools");
    }
    
    auto vp          = app.make<UIPanel>("##View");
    {
        vp.flag(SET, UIFlag::NoDecoration);
        vp.left("PalettePanel", RIGHT);
        vp.top("ToolBar", BOTTOM);
    
        auto xgv = vp.make<XGView>();
        xgv.uid("View");
    }


    
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

void XGWin::_open(const std::filesystem::path&fp)
{
    // TODO
}

void XGWin::_save(const std::filesystem::path&fp)
{
    // TODO
    return;

    if(fp != m_filepath){
        m_filepath  = fp;
    }
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
    if(m_filepath.empty()){
        cmd_file_saveas();
    } else
        _save(m_filepath);
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
