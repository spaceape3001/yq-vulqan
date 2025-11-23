////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFWin.hpp"
#include "GLTFTree.hpp"

#include <yq/core/Logging.hpp>
#include <yq/assetvk/ui/UIPanelWriter.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/io/GLTFLoader.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/tachyon/command/ui/TitleCommand.hpp>
#include <ImGuiFileDialog.h>
#include <tiny_gltf.h>

void GLTFWin::init_meta()
{
    auto w = writer<GLTFWin>();

    auto app        = w.imgui(UI, APP);
    auto mmb        = app.menubar(MAIN);

    auto file       = mmb.menu("File");
    file.menuitem("Open").action(&GLTFWin::cmd_file_open);
    file.menuitem("Save").action(&GLTFWin::cmd_file_save);
    file.menuitem("Save As").action(&GLTFWin::cmd_file_saveas);

    auto tp = app.make<UIPanel>("##TreePanel");
    tp.uid("TreePanel");
    auto gt = tp.make<GLTFTree>();
    gt.uid("GLTFTree");

}

GLTFWin::GLTFWin()
{
}

GLTFWin::~GLTFWin()
{
}
    


void GLTFWin::_save(const std::filesystem::path& fp)
{
    // TODO
    return;

    if(fp != m_filepath){
        m_filepath  = fp;
        update_title();
    }
}


void GLTFWin::cmd_file_open()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Open", ".gltf", config);        
    m_fileMode  = FileMode::Open;
}

void GLTFWin::cmd_file_save()
{
    if(m_filepath.empty()){
        cmd_file_saveas();
    } else
        _save(m_filepath);
}

void GLTFWin::cmd_file_saveas()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    config.flags |= ImGuiFileDialogFlags_ConfirmOverwrite;
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Save", ".gltf", config);        
    m_fileMode  = FileMode::Save;
}

void GLTFWin::imgui(ViContext&u) 
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

void GLTFWin::open(const std::filesystem::path& fp)
{
    auto mdl    = raw_load_gltf(fp);
    if(!mdl){
        yWarning() << "Unable to load the GLTF file: " << fp;
        return ;
    }
    
    m_model     = mdl;
    
    if(m_tree){
        m_tree -> model(SET, m_model);
    }

    yInfo() << "Loaded file: " << fp;

    m_filepath  = fp;
    update_title();
}

Execution   GLTFWin::setup(const Context&ctx) 
{
    Execution ret =  Widget::setup(ctx);
    if(!m_tree){
        m_tree  = dynamic_cast<GLTFTree*>(element(FIRST, "GLTFTree"));
        if(m_model && m_tree)
            m_tree -> model(SET, m_model);
    }
    
    return ret;
}


void GLTFWin::update_title()
{
    std::string t;
    if(m_filepath.empty()){
        t   = "GLTFEdit";
    } else {
        t   = std::format("{} - {} - GLTFEdit", m_filepath.stem().string(), m_filepath.parent_path().string());
    }
    yInfo() << "Sending command to alter title to :" << t;
    send(new TitleCommand({.target={ Type::Viewer, viewer().id }}, t));
}

YQ_TACHYON_IMPLEMENT(GLTFWin)
