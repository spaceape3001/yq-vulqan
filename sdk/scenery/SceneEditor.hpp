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
    class SceneInfo;
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
    
    static void init_info();
    
    enum class E {
        Invisible,
        OriginFix,
        HUD
    };
    
    using EFlags    = Flags<E>;
    
    static EFlags       flags_for(const SceneInfo&);
    
    struct Entry {
        SceneID             scene;
        const SceneInfo*    info    = nullptr;
        std::string         name;
        std::string         filepath;
        RGBA4F              gamma  = { 0., 0., 0., -1.};
        EFlags              flags;
    };
    
    std::vector<Entry>      m_scenes;
    Entry*                  m_editing   = nullptr;
    
    Entry*                  entry(SceneID);
    const Entry*            entry(SceneID) const;
    
    Entry*                  _add(const Scene&);
    
    
    struct {
        CameraID            space;
        CameraID            hud;
    }   m_camera;
    
    void    create_scene(const SceneInfo&);
    void    add_scene(SceneCPtr);

    void    cmd_new_back_scene();
    void    cmd_new_fore_scene();
    void    cmd_new_hud_scene();
    void    cmd_new_simple_scene();
    
    class UIScenes;
    
    virtual Execution   setup(const Context&) override;
    
    void    _rebuild();
};
