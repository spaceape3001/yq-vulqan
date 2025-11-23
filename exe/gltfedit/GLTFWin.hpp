////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
}

using namespace yq;
using namespace yq::tachyon;

class GLTFTree;

class GLTFWin : public Widget {
    YQ_TACHYON_DECLARE(GLTFWin, Widget)
public:
    enum class FileMode {
        None, 
        Open,
        Save
    };
    
    GLTFWin();
    ~GLTFWin();
    
    static void init_meta();

    void imgui(ViContext&) override;
    virtual Execution   setup(const Context&) override;

private:
    FileMode                m_fileMode = FileMode::None;
    GLTFTree*               m_window    = nullptr;
    std::filesystem::path   m_filepath;
    
    void    cmd_file_open();
    void    cmd_file_save();
    void    cmd_file_saveas();
    void _open(const std::filesystem::path&);
    void _save(const std::filesystem::path&);
};

