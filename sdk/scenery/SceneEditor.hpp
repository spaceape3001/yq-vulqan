////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/CompositeWidget.hpp>

namespace yq::tachyon {
    class OpenFileRequest;
    class SaveFileRequest;
}

using namespace yq;
using namespace yq::tachyon;

class SceneEditor : public CompositeWidget {
    YQ_TACHYON_DECLARE(SceneEditor, CompositeWidget)
public:

    SceneEditor();
    ~SceneEditor();
    
    //bool    menubar(enabled_k) const override { return true; }
    //void    menubar(ViContext&) override;
    using Widget::imgui;
    void    imgui(ViContext&) override;
    
    void    scene_panel();

    static void init_info();
    
    struct Entry {
        SceneID         scene;
        std::string     name, type;
        std::string     filepath;
        CameraID        camera;
        RGBA4F          gamma;
    };
    
    std::vector<Entry>      m_scenes;
};
