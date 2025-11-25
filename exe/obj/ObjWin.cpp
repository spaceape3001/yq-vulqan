////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ObjWin.hpp"
#include "ObjTree.hpp"

#include <yq/core/Logging.hpp>
#include <yq/assetvk/ui/UIPanelWriter.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
//#include <yq/tachyon/io/ObjLoader.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/tachyon/command/ui/TitleCommand.hpp>
#include <ImGuiFileDialog.h>
//#include <tiny_obj.h>

void ObjWin::init_meta()
{
    auto w = writer<ObjWin>();

    auto app        = w.imgui(UI, APP);
    auto mmb        = app.menubar(MAIN);

    auto file       = mmb.menu("File");
    file.menuitem("Open").action(&ObjWin::cmd_file_open);
    file.menuitem("Save").action(&ObjWin::cmd_file_save);
    file.menuitem("Save As").action(&ObjWin::cmd_file_saveas);

    auto tp = app.make<UIPanel>("##TreePanel");
    tp.uid("TreePanel");
    tp.flag(SET, UIFlag::NoDecoration);

    auto gt = tp.make<ObjTree>();
    gt.uid("ObjTree");

}

ObjWin::ObjWin()
{
}

ObjWin::~ObjWin()
{
}
    


void ObjWin::_save(const std::filesystem::path& fp)
{
    // TODO
    return;

    if(fp != m_filepath){
        m_filepath  = fp;
        update_title();
    }
}


void ObjWin::cmd_file_open()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Open", ".Obj", config);        
    m_fileMode  = FileMode::Open;
}

void ObjWin::cmd_file_save()
{
    if(m_filepath.empty()){
        cmd_file_saveas();
    } else
        _save(m_filepath);
}

void ObjWin::cmd_file_saveas()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    config.flags |= ImGuiFileDialogFlags_ConfirmOverwrite;
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Save", ".Obj", config);        
    m_fileMode  = FileMode::Save;
}

void ObjWin::imgui(ViContext&u) 
{
    Widget::imgui(UI, u);
    if(m_fileMode != FileMode::None){
        ImVec2  minSize = { (float)(0.5 * width()), (float)(0.5 * height()) };
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoCollapse, minSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                switch(m_fileMode){
                case FileMode::None:
                    break;
                case FileMode::Save:
                    _save(filePathName);
                    break;
                case FileMode::Open:
                    open(filePathName);
                    break;
                }
            }
            m_fileMode      = FileMode::None;
            ImGuiFileDialog::Instance()->Close();
        }
    }
}

void ObjWin::open(const std::filesystem::path& fp)
{
    tinyobj::ObjReaderConfig cfg;
    cfg.triangulate = false;
    ObjReaderSPtr   mdl = std::make_shared<tinyobj::ObjReader>();
    if(!mdl->ParseFromFile(fp.string())){
        yWarning() << "Unable to load the obj file: '" << fp << "' (" << mdl->Error() << ")";
        return ;
    }
    
    
    m_model     = mdl;
    
    if(m_tree){
        m_tree -> model(SET, m_model, fp);
    }

    yInfo() << "Loaded file: " << fp;

    m_filepath  = fp;
    update_title();
}

Execution   ObjWin::setup(const Context&ctx) 
{
    Execution ret =  Widget::setup(ctx);
    if(!m_tree){
        m_tree  = dynamic_cast<ObjTree*>(element(FIRST, "ObjTree"));
        if(m_model && m_tree)
            m_tree -> model(SET, m_model, m_filepath);
    }
    
    return ret;
}


void ObjWin::update_title()
{
    std::string t;
    if(m_filepath.empty()){
        t   = "ObjEdit";
    } else {
        t   = std::format("{} - {} - ObjEdit", m_filepath.stem().string(), m_filepath.parent_path().string());
    }
    yInfo() << "Sending command to alter title to :" << t;
    send(new TitleCommand({.target={ Type::Viewer, viewer().id }}, t));
}

YQ_TACHYON_IMPLEMENT(ObjWin)
