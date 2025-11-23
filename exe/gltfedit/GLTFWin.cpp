////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFWin.hpp"
#include "GLTFTree.hpp"

#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <ImGuiFileDialog.h>

void GLTFWin::init_meta()
{
    auto w = writer<GLTFWin>();

    auto app        = w.imgui(UI, APP);
    auto mmb        = app.menubar(MAIN);

    auto file       = mmb.menu("File");
    file.menuitem("Open").action(&GLTFWin::cmd_file_open);
    file.menuitem("Save").action(&GLTFWin::cmd_file_save);
    file.menuitem("Save As").action(&GLTFWin::cmd_file_saveas);

}

GLTFWin::GLTFWin()
{
}

GLTFWin::~GLTFWin()
{
}
    
void GLTFWin::_open(const std::filesystem::path&)
{
    // TODO
}

void GLTFWin::_save(const std::filesystem::path& fp)
{
    // TODO
    return;

    if(fp != m_filepath){
        m_filepath  = fp;
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
                    _open(filePathName);
                    break;
                }
            }
            m_fileMode      = FileMode::None;
            ImGuiFileDialog::Instance()->Close();
        }
    }
}

Execution   GLTFWin::setup(const Context&ctx) 
{
    Execution ret =  Widget::setup(ctx);
    
    return ret;
}

YQ_TACHYON_IMPLEMENT(GLTFWin)
