////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Obj.hpp"
#include <yq/tachyon/api/Widget.hpp>
//#include <yq/tachyon/typedef/Obj.hpp>

namespace yq::tachyon {
}

using namespace yq;
using namespace yq::tachyon;

class ObjTree;

class ObjWin : public Widget {
    YQ_TACHYON_DECLARE(ObjWin, Widget)
public:
    enum class FileMode {
        None, 
        Open,
        Save
    };
    
    ObjWin();
    ~ObjWin();
    
    static void init_meta();

    void imgui(ViContext&) override;
    virtual Execution   setup(const Context&) override;

    void    open(const std::filesystem::path&);

private:
    FileMode                m_fileMode = FileMode::None;
    ObjTree*                m_tree    = nullptr;
    std::filesystem::path   m_filepath;
    ObjReaderSPtr           m_model;
    
    void    cmd_file_open();
    void    cmd_file_save();
    void    cmd_file_saveas();
    
    //bool    okay_to_close();
    
    void    _save(const std::filesystem::path&);
    
    void    update_title();
};

