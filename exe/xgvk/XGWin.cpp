////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGWin.hpp"
//#include "PalettePanel.hpp"
//#include "ViewPanel.hpp"

#include <yq/xg/XGElement.hpp>
#include <yq/assetvk/menu/CreateMenuUI.hpp>
#include <yq/assetvk/ui/UIBuildableMetaListWriter.hpp>

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/ui/UIPanel.hpp>
#include <yq/tachyon/ui/UIPanelWriter.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/xgvk/command/OpenXGFileCommand.hpp>
#include <yq/xgvk/command/SaveXGFileCommand.hpp>
#include <yq/xgvk/gesture/OpenXGFileGesture.hpp>
#include <yq/xgvk/gesture/SaveXGFileGesture.hpp>
#include <yq/xgvk/ui/XGView.hpp>
#include <yq/xgvk/ui/XGViewWriter.hpp>
#include <ImGuiFileDialog.h>

YQ_TACHYON_IMPLEMENT(XGWin)

using namespace yq;
using namespace yq::tachyon;

void XGWin::init_meta()
{
    auto w = writer<XGWin>();
    w.slot(&XGWin::on_open_xg_file_command);
    w.slot(&XGWin::on_save_xg_file_command);

    auto app        = w.imgui(UI, APP);
    auto mmb        = app.menubar(MAIN);
    
    auto ppw         = app.make<UIPanel>("##Pallette");
    {
        ppw.uid("PalettePanel");
        ppw.flag(SET, UIFlag::NoDecoration);    // until min/max work
        //ppw.width(MINIMUM, PIVOT, 0.20);
        //ppw.width(MAXIMUM, PIVOT, 0.80);
        ppw.right(PIVOT, 0.20); //temporary
        auto x = ppw.make<UIBuildableMetaList<XGElement>>();
        x.flag(SET, UIFlag::EmitSignal);
        x.drag_type("meta");
        
        // do something smart, like categories (including templates)
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


    
    auto fileMenu       = mmb.menu("File");
    auto editMenu       = mmb.menu("Edit");
    auto viewMenu       = mmb.menu("View");
    auto xgMenu         = mmb.menu("XG");
    
    fileMenu.menuitem("Open").action(&XGWin::cmd_file_open);
    fileMenu.menuitem("Save").action(&XGWin::cmd_file_save);
    fileMenu.menuitem("Save As").action(&XGWin::cmd_file_saveas);

    viewMenu.checkbox("Tools").action(VISIBLE, ttb);
    viewMenu.checkbox("Palette").action(VISIBLE, ppw);

    //(xgMenu << new CreateMenuUI("Add/Create##AddXGUI", meta<XGElement>())); // .action(&SceneEditor::action_create_light);

}

XGWin::XGWin(XGDocumentPtr dp) : m_document(dp)
{
    m_flags |= F::Gesture;
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
    gesture(new OpenXGFileGesture(*this));
    //IGFD::FileDialogConfig config;
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
    gesture(new SaveXGFileGesture(*this));
}

void    XGWin::imgui(ViContext&u) 
{
    Widget::imgui(UI,u);
    Widget::imgui(u);
}

void XGWin::on_open_xg_file_command(const OpenXGFileCommand&cmd)
{
    if(cmd.target() != id())
        return;
    _open(cmd.file());
}

void XGWin::on_save_xg_file_command(const SaveXGFileCommand&cmd)
{
    if(cmd.target() != id())
        return;
    _save(cmd.file());
}

