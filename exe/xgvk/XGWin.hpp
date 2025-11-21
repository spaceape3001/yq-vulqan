////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>
#include <yq/xg/XGDocument.hpp>

using namespace yq;
using namespace yq::tachyon;
using namespace yq::xg;

class XGWin : public Widget {
    YQ_TACHYON_DECLARE(XGWin, Widget)
public:

    XGWin(XGDocumentPtr dp={});
    ~XGWin();
    
    void    imgui(ViContext&u) ;
    static void init_meta();
    
    enum class FileMode {
        None,
        Open,
        Save
    };

    std::filesystem::path   m_filepath;
    FileMode                m_fileMode  = FileMode::None;
    XGDocumentPtr           m_document;
    
    void    cmd_file_open();
    void    cmd_file_save();
    void    cmd_file_saveas();
    void    _open(const std::filesystem::path&);
    void    _save(const std::filesystem::path&);
};
