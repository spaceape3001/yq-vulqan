////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/CompositeWidget.hpp>
#include <tachyon/typedef/controller.hpp>

namespace yq::tachyon {
    class CameraInfo;
    class InfoSelectionChangedEvent;
    class LoadTSXReply;
    class OpenFileRequest;
    class RenderedInfo;
    class SaveFileRequest;
    class SaveTSXReply;
    class SceneInfo;
}

namespace IGFD { class FileDialog; }

using namespace yq;
using namespace yq::tachyon;

class InspectorUI;

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
    static EFlags       flags_for(const CameraInfo&);
    
    
    
    void    create_camera(const CameraInfo&);
    void    create_rendered(const RenderedInfo&);
    void    create_scene(const SceneInfo&);


    void    cmd_file_open();
    void    cmd_file_save();
    void    cmd_file_save_as();
    void    cmd_file_new();

    void    cmd_new_back_scene();
    void    cmd_new_fore_scene();
    void    cmd_new_hud_scene();
    void    cmd_new_simple_scene();
    
    void    cmd_create_rendered();
    
    void    cmd_add_scene(const SceneInfo&);
    void    cmd_add_camera(const CameraInfo&);
    
    virtual Execution   setup(const Context&) override;
    virtual Execution   teardown(const Context&) override;
    
    virtual void    prerecord(ViContext&) override;
    
    //void    ui_scene_entries();

    class CameraAddMenuUI;
    class CameraTableUI;
    class SceneAddMenuUI;
    class ScenesTableUI;
    class RenderedTableUI;
    class RenderedAddMenuUI;
    
private:
    struct SceneEntry;
    struct CameraEntry;
    struct RenderedEntry;
    
    struct {
        TypedID                     space;
        CameraID                    hud;
        
        //! Current selected (available)
        const CameraInfo*           info  = nullptr;
        
        //! All entries (might move to camera table UI)
        std::vector<CameraEntry>    entries;

        //! For the entries
        CameraID                    selected;
        
        //! Current "editing" ... will be deprecated/removed (use selected instead)
        CameraEntry*                editing     = nullptr;
        InspectorUI*                properties  = nullptr;
    }                           m_camera;
    
    struct {
        const SceneInfo*            info        = nullptr;
        SceneID                     selected;
        std::vector<SceneEntry>     entries;

        //! Current "editing" ... will be deprecated/removed (use selected instead)
        SceneEntry*                 editing     = nullptr;
        InspectorUI*                properties  = nullptr;
    }                           m_scene;

    struct {
        const RenderedInfo*         info     = nullptr;
        std::vector<RenderedEntry>  entries;
        RenderedID                  selected;
        InspectorUI*                properties  = nullptr;
    }                           m_rendered;
    
    //SceneEntry*                 m_editing   = nullptr;
    //std::vector<SceneEntry>     m_scenes;
    FileMode                    m_fileMode  = FileMode::None;
    Flags<F>                    m_flags;
    TypedID                     m_fileIO;
    std::filesystem::path       m_filepath;
    //IGFD::FileDialog*       m_importDialog = nullptr;
    //IGFD::FileDialog*       m_exportDialog = nullptr;
    TypedID                     m_controller;
    bool                        m_controllerInit  = false;

    void                        _activate(CameraID);
    void                        _activate(SceneID);
    void                        _activate(RenderedID);

    SceneEntry*                 _add(const Scene&);
    CameraEntry*                _add(const Camera&);
    
    void                        _clear();
    SceneEntry*                 _entry(SceneID);
    const SceneEntry*           _entry(SceneID) const;

    CameraEntry*                 _entry(CameraID);
    const CameraEntry*           _entry(CameraID) const;

    void                        _rebuild();
    void                        _title();

    void    _open(const std::filesystem::path&);
    void    _save(const std::filesystem::path&);
    
    void    on_load_tsx_reply(const LoadTSXReply&);
    void    on_save_tsx_reply(const SaveTSXReply&);
    void    on_info_selection_changed_event(const InfoSelectionChangedEvent&);
};

extern TypedID     gFileIO;
