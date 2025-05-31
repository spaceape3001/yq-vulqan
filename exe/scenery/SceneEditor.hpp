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
    class SaveTSXReply;
    class LoadTSXReply;
    class CameraInfo;
}

namespace IGFD { class FileDialog; }

class SceneTable;

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


    enum class FileMode {
        None,
        Open,
        Save
    };
    
    enum class E {
        Selected,
        Invisible,
        OriginFix,
        HUD
    };
    
    enum class F {
        Stale
    };
    
    using EFlags    = Flags<E>;
    
    static EFlags       flags_for(const SceneInfo&);
    
    
    
    void    create_scene(const SceneInfo&);


    void    cmd_file_open();
    void    cmd_file_save();
    void    cmd_file_save_as();
    void    cmd_file_new();

    void    cmd_new_back_scene();
    void    cmd_new_fore_scene();
    void    cmd_new_hud_scene();
    void    cmd_new_simple_scene();
    
    void    cmd_add_scene(const SceneInfo&);
    void    cmd_add_camera(const CameraInfo&);
    
    virtual Execution   setup(const Context&) override;
    virtual Execution   teardown(const Context&) override;
    
    virtual void    prerecord(ViContext&) override;
    
    //void    ui_scene_table();

    class UICameraAddMenu;
    class UICamerasTable;
    class UICameraPalette;
    class UIScenesTable;
    class UISceneAddMenu;
    
    class UICameraCreateMenu;
    class UISceneCreateMenu;
    
private:
    struct SceneEntry;
    struct CameraEntry;
    
    struct {
        CameraID            space;
        CameraID            hud;

    }                           m_camera;
    SceneEntry*                 m_editing   = nullptr;
    std::vector<SceneEntry>     m_scenes;
    std::vector<CameraEntry>    m_cameras;
    FileMode                    m_fileMode  = FileMode::None;
    Flags<F>                    m_flags;
    TypedID                     m_fileIO;
    std::filesystem::path       m_filepath;
    //IGFD::FileDialog*       m_importDialog = nullptr;
    //IGFD::FileDialog*       m_exportDialog = nullptr;

    SceneEntry*                 _add(const Scene&);
    void                        _clear();
    SceneEntry*                 _entry(SceneID);
    const SceneEntry*           _entry(SceneID) const;
    void                        _rebuild();
    void                        _title();

    void    _open(const std::filesystem::path&);
    void    _save(const std::filesystem::path&);
    
    void    on_load_tsx_reply(const LoadTSXReply&);
    void    on_save_tsx_reply(const SaveTSXReply&);
};
