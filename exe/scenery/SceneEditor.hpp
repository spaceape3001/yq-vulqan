////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/CompositeWidget.hpp>
#include <tachyon/typedef/camera.hpp>
#include <tachyon/typedef/camera3.hpp>
#include <tachyon/typedef/controller.hpp>
#include <tachyon/typedef/light.hpp>
#include <tachyon/typedef/light3.hpp>
#include <tachyon/typedef/model.hpp>
#include <tachyon/typedef/rendered.hpp>
#include <tachyon/typedef/rendered3.hpp>
#include <tachyon/typedef/scene.hpp>
#include <tachyon/typedef/spatial.hpp>
#include <yq/core/Future.hpp>

namespace yq::tachyon {
    class InfoSelectionChangedEvent;
    class LightInfo;
    class LoadTSXReply;
    class OpenFileRequest;
    class SaveFileRequest;
    class SaveTSXReply;
    class ViewerScreenshotReply;
    struct Payload;
}

namespace IGFD { class FileDialog; }

using namespace yq;
using namespace yq::tachyon;

class InspectorUI;
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

    static void     clear_edit_thread();
    static void     clear_aux_thread();
    static void     clear_thread(ThreadID);

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
    
    static void             init_info();

    SceneEditor();
    ~SceneEditor();
    
    //bool    menubar(enabled_k) const override { return true; }
    //void    menubar(ViContext&) override;
    using Widget::imgui;
    void    imgui(ViContext&) override;
    


    using EFlags    = Flags<E>;
    
    static EFlags       flags_for(const SceneInfo&);
    static EFlags       flags_for(const CameraInfo&);

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

    void                cmd_file_open();
    void                cmd_file_save();
    void                cmd_file_save_as();
    void                cmd_file_new();
    
    void                cmd_screenshot();

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
    
private:
    struct SceneEntry;
    
    struct {
        TypedID                 space;
        TypedID                 hud;
        CameraTableUI*          table       = nullptr;
        InspectorUI*            properties  = nullptr;
        const CameraInfo*       info        = nullptr;
        CameraID                selected;
    } m_camera;
    
    struct {
        TypedID                 space;
        const ControllerInfo*   info        = nullptr;
        ControllerTableUI*      table       = nullptr;
        ControllerID            selected;
        InspectorUI*            properties  = nullptr;
        bool                    init        = false;
    } m_controller;
    
    struct {
        //  TODO
    } m_collision;
    
    struct {
        const LightInfo*        info        = nullptr;
        LightTableUI*           table       = nullptr;
        LightID                 selected;
        InspectorUI*            properties  = nullptr;
    } m_light;

    struct {
        const ModelInfo*        info        = nullptr;
        ModelTableUI*           table       = nullptr;
        ModelID                 selected;
        InspectorUI*            properties  = nullptr;
    } m_model;

    struct {
        const RenderedInfo*     info        = nullptr;
        RenderedTableUI*        table       = nullptr;
        RenderedID              selected;
        InspectorUI*            properties  = nullptr;
    } m_rendered;
    
    struct {
        const SceneInfo*        info        = nullptr;
        SceneID                 selected;
        TypedID                 simple;     //!< The default simple scene
        InspectorUI*            properties  = nullptr;
        SceneTableUI*           table       = nullptr;
        bool                    rebuild     = false;
    } m_scene;

    struct {
        const SpatialInfo*      info        = nullptr;
        TypedID                 context;
    } m_spatial;

    FileMode                    m_fileMode  = FileMode::None;
    TypedID                     m_fileIO;
    std::filesystem::path       m_filepath;
    bool                        m_defaultInit   = false;

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

    CameraID        _create(const CameraInfo&);
    SpatialID       _create(camera_k, const SpatialInfo&);
    SpatialID       _create(Camera³ID, const SpatialInfo&);
    ControllerID    _create(const ControllerInfo&);
    LightID         _create(const LightInfo&);
    SpatialID       _create(light_k, const SpatialInfo&);
    SpatialID       _create(Light³ID, const SpatialInfo&);
    ModelID         _create(const ModelInfo&);
    RenderedID      _create(const RenderedInfo&);
    SpatialID       _create(rendered_k, const SpatialInfo&);
    SpatialID       _create(Rendered³ID, const SpatialInfo&);
    SceneID         _create(const SceneInfo&);
    
    void            _schedule(StdThread, TachyonPtrVector&&);
    void            _schedule(ThreadID, TachyonPtrVector&&);

    void    _clear();

    void    _rebuild();
    void    _title();

    void    _open(const std::filesystem::path&);
    void    _save(const std::filesystem::path&);
    
    void    on_camera_select_event(const CameraSelectEvent&);
    void    on_controller_select_event(const ControllerSelectEvent&);
    void    on_info_selection_changed_event(const InfoSelectionChangedEvent&);
    void    on_light_select_event(const LightSelectEvent&);
    void    on_load_tsx_reply(const LoadTSXReply&);
    void    on_model_select_event(const ModelSelectEvent&);
    void    on_rendered_select_event(const RenderedSelectEvent&);
    void    on_save_tsx_reply(const SaveTSXReply&);
    void    on_scene_add_event(const SceneAddEvent&);
    void    on_scene_remove_event(const SceneRemoveEvent&);
    void    on_scene_select_event(const SceneSelectEvent&);
    void    on_scene_visibility_event(const SceneVisibilityEvent&);
    void    on_viewer_screenshot_reply(const ViewerScreenshotReply&);
    
    Future<void>        m_defaultLoad;
};

extern TypedID     gFileIO;
