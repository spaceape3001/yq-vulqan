////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/widget/CompositeWidget.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tachyon/typedef/controller.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tachyon/typedef/model.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/spatial.hpp>
#include <yq/core/Future.hpp>

#define FRAME_INSPECTOR  0

namespace yq::tachyon {
    class LuaExecuteReply;
    class MetaSelectionChangedEvent;
    class LightMeta;
    class LoadTSXReply;
    class LuaWindowUI;
    class OpenFileRequest;
    class SaveFileRequest;
    class SaveTSXReply;
    class ViewerScreenshotReply;
    struct Payload;
    class UITachyonEditor;
    class FrameInspector;
}

namespace IGFD { class FileDialog; }

using namespace yq;
using namespace yq::tachyon;

class CameraTableUI;
class CameraSelectEvent;
class ControllerTableUI;
class ControllerSelectEvent;
class LightTableUI;
class LightSelectEvent;
class ModelTableUI;
class ModelSelectEvent;
class PhysicsTableUI;
class PhysicsSelectEvent;
class RenderedTableUI;
class RenderedSelectEvent;
class SceneAddEvent;
class SceneRemoveEvent;
class SceneSelectEvent;
class SceneVisibilityEvent;
class SceneTableUI;



class SceneEditor : public CompositeWidget {
    YQ_TACHYON_DECLARE(SceneEditor, CompositeWidget)
public:

    using PostStartupFN = std::function<void(SceneEditor&)>;

    static void     clear_edit_thread();
    static void     clear_aux_thread();
    static void     clear_thread(ThreadID);

    enum class FileMode {
        None,
        Import,
        Open,
        Save,
        Lua
    };
    
    enum class E {
        Selected,
        Invisible,
        OriginFix,
        HUD
    };
    
    static void             init_meta();

    struct Param : public CompositeWidget::Param {
        // Called end of setup() right *before* going live
        PostStartupFN           startup;
    };

    SceneEditor();
    SceneEditor(PostStartupFN&& fn);
    ~SceneEditor();
    
    //bool    menubar(enabled_k) const override { return true; }
    //void    menubar(ViContext&) override;
    using Widget::imgui;
    void    imgui(ViContext&) override;
    


    using EFlags    = Flags<E>;
    
    static EFlags       flags_for(const SceneMeta&);
    static EFlags       flags_for(const CameraMeta&);

    void                action_create_camera(const Payload&);
    void                action_create_camera_spatial(const Payload&);
    void                action_create_controller(const Payload&);
    void                action_create_light(const Payload&);
    void                action_create_light_spatial(const Payload&);
    void                action_create_model(const Payload&);
    //void                action_create_physics(const Payload&);          // TODO....
    void                action_create_rendered(const Payload&);
    void                action_create_rendered_spatial(const Payload&);
    void                action_create_scene(const Payload&);


    void                cmd_file_import();
    void                cmd_file_open();
    void                cmd_file_save();
    void                cmd_file_save_as();
    void                cmd_file_new();
    
    void                cmd_file_lua_execute();

    void                cmd_screenshot();

    void                cmd_time_pause();
    void                cmd_time_resume();
    

    CameraID            selected(camera_k) const { return m_camera.selected; }
    ControllerID        selected(controller_k) const { return m_controller.selected; }
    LightID             selected(light_k) const { return m_light.selected; }
    ModelID             selected(model_k) const { return m_model.selected; }
    RenderedID          selected(rendered_k) const { return m_rendered.selected; }
    SceneID             selected(scene_k) const { return m_scene.selected; }
    
    
    virtual Execution   setup(const Context&) override;
    virtual Execution   tick(const Context&) override;
    virtual Execution   teardown(const Context&) override;
    
    virtual void    prerecord(ViContext&) override;
    
    //void    ui_scene_entries();

    class ScenesTableUI;

    void    _open(const std::filesystem::path&, StdThread st=EDIT);
    void    _import(const std::filesystem::path&, StdThread st=EDIT);
    void    _save(const std::filesystem::path&, ThreadSpec st=EDIT);
    void    _lua(const std::filesystem::path&);
    
private:
    struct SceneEntry;
    
    struct {
        TypedID                 space;
        TypedID                 hud;
        CameraTableUI*          table       = nullptr;
        UITachyonEditor*        properties  = nullptr;
        const CameraMeta*       meta        = nullptr;
        CameraID                selected;
    } m_camera;
    
    struct {
        TypedID                 space;
        const ControllerMeta*   meta        = nullptr;
        ControllerTableUI*      table       = nullptr;
        ControllerID            selected;
        UITachyonEditor*        properties  = nullptr;
        bool                    init        = false;
    } m_controller;
    
    struct {
        //  TODO
    } m_collision;
    
    struct {
        const LightMeta*        meta        = nullptr;
        LightTableUI*           table       = nullptr;
        LightID                 selected;
        UITachyonEditor*        properties  = nullptr;
    } m_light;

    struct {
        const ModelMeta*        meta        = nullptr;
        ModelTableUI*           table       = nullptr;
        ModelID                 selected;
        UITachyonEditor*        properties  = nullptr;
    } m_model;

    struct {
        const RenderedMeta*     meta        = nullptr;
        RenderedTableUI*        table       = nullptr;
        RenderedID              selected;
        UITachyonEditor*        properties  = nullptr;
    } m_rendered;
    
    struct {
        const SceneMeta*        meta        = nullptr;
        SceneID                 selected;
        TypedID                 simple;     //!< The default simple scene
        UITachyonEditor*        properties  = nullptr;
        SceneTableUI*           table       = nullptr;
        bool                    rebuild     = false;
    } m_scene;

    struct {
        const SpatialMeta*      meta        = nullptr;
        TypedID                 context;
    } m_spatial;

    FileMode                m_fileMode  = FileMode::None;
    TypedID                 m_fileIO;
    std::filesystem::path   m_filepath;
    PostStartupFN           m_startup;
    bool                    m_defaultInit   = false;
    unsigned int            m_number        = 1;
    
    struct {
        LuaWindowUI*            panel           = nullptr;
        TypedID                 tvm;
    } m_lua;

#if FRAME_INSPECTOR
    //! Used for debugging....
    Ref<FrameInspector>     m_inspector;
#endif

    //! Loads (but not schedule) the given TSX file
    static Expect<TachyonPtrVector>     _load(const std::filesystem::path&);
    void                                _default();
    Expect<TachyonPtrVector>            _default_load(std::string_view pp="exe/scenery/default.tsx");

    void            _activate(SceneID);
    void            _activate(CameraID);
    void            _activate(ControllerID);
    void            _activate(LightID);
    void            _activate(ModelID);
    void            _activate(RenderedID);

    void            _load(StdThread, const std::filesystem::path&);

    CameraID        _create(const CameraMeta&);
    SpatialID       _create(camera_k, const SpatialMeta&);
    SpatialID       _create(Camera³ID, const SpatialMeta&);
    ControllerID    _create(const ControllerMeta&);
    LightID         _create(const LightMeta&);
    SpatialID       _create(light_k, const SpatialMeta&);
    SpatialID       _create(Light³ID, const SpatialMeta&);
    ModelID         _create(const ModelMeta&);
    RenderedID      _create(const RenderedMeta&);
    SpatialID       _create(rendered_k, const SpatialMeta&);
    SpatialID       _create(Rendered³ID, const SpatialMeta&);
    SceneID         _create(const SceneMeta&);
    
    void            _schedule(StdThread, TachyonPtrVector&&);
    void            _schedule(ThreadID, TachyonPtrVector&&);

    void    _clear();

    void    _rebuild();
    void    _title();

    
    void    on_camera_select_event(const CameraSelectEvent&);
    void    on_controller_select_event(const ControllerSelectEvent&);
    void    on_light_select_event(const LightSelectEvent&);
    void    on_load_tsx_reply(const LoadTSXReply&);
    void    on_lua_exec_reply(const LuaExecuteReply&);
    void    on_meta_selection_changed_event(const MetaSelectionChangedEvent&);
    void    on_model_select_event(const ModelSelectEvent&);
    void    on_rendered_select_event(const RenderedSelectEvent&);
    void    on_save_tsx_reply(const SaveTSXReply&);
    void    on_scene_add_event(const SceneAddEvent&);
    void    on_scene_remove_event(const SceneRemoveEvent&);
    void    on_scene_select_event(const SceneSelectEvent&);
    void    on_scene_visibility_event(const SceneVisibilityEvent&);
    void    on_viewer_screenshot_reply(const ViewerScreenshotReply&);
    
    Future<void>        m_defaultLoad;
    
    static void init_slots();
    static void init_ui();
};

extern TypedID     gFileIO;
