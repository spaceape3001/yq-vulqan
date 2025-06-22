////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/CompositeWidget.hpp>
#include <tachyon/typedef/controller.hpp>
#include <tachyon/typedef/camera.hpp>
#include <tachyon/typedef/light.hpp>
#include <tachyon/typedef/model.hpp>
#include <tachyon/typedef/rendered.hpp>
#include <tachyon/typedef/scene.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {
    class InfoSelectionChangedEvent;
    class LightInfo;
    class LoadTSXReply;
    class OpenFileRequest;
    class SaveFileRequest;
    class SaveTSXReply;
    struct Payload;
}

namespace IGFD { class FileDialog; }

using namespace yq;
using namespace yq::tachyon;

class InspectorUI;
class CameraTableUI;
class CameraSelectEvent;
class LightTableUI;
class LightSelectEvent;
class ModelTableUI;
class ModelSelectEvent;
class PhysicsTableUI;
class PhysicsSelectEvent;
class RenderedTableUI;
class RenderedSelectEvent;
//class SceneTableUI;
//class SceneSelectEvent;

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
    
    /*
    CameraID    _create(const CameraInfo&);
    LightID     _create(const LightInfo&);
    ModelID     _create(const ModelInfo&);
    RenderedID  _create(const RenderedInfo&);
    SceneID     _create(const SceneInfo&);
    SpatialID   _create(const SpatialInfo&);
    
    SpatialID   _create(Camera³ID, const SpatialInfo&);
    SpatialID   _create(Light³ID, const SpatialInfo&);
    //SpatialID   _create(Model³ID, const SpatialInfo&);
    SpatialID   _create(Rendered³ID, const SpatialInfo&);

    */
    
    void        create_payload(const Payload&);
    
    TypedID     create(const CameraInfo&);
    //LightID     create(const LightInfo&);
    //ModelID     create(const ModelInfo&);
    TypedID     create(const RenderedInfo&);
    TypedID     create(const SceneInfo&);
    //SpatialID   create(const SpatialInfo&);
    
    //SpatialID   create(Camera³ID, const SpatialInfo&);
    //SpatialID   create(Light³ID, const SpatialInfo&);
    //SpatialID   create(Model³ID, const SpatialInfo&);
    //SpatialID   create(Rendered³ID, const SpatialInfo&);

    void    action_create_camera(const Payload&);
    void    action_create_light(const Payload&);
    void    action_create_model(const Payload&);
    void    action_create_physics(const Payload&);          // TODO....
    void    action_create_rendered(const Payload&);
    void    action_create_spatial(const Payload&);
    void    action_create_scene(const Payload&);

    void    cmd_file_open();
    void    cmd_file_save();
    void    cmd_file_save_as();
    void    cmd_file_new();

    void    cmd_add_scene(const SceneInfo&);
    void    cmd_add_camera(const CameraInfo&);
    
    virtual Execution   setup(const Context&) override;
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
    } m_camera;
    
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
        const SceneInfo*            info        = nullptr;
        SceneID                     selected;
        std::vector<SceneEntry>     entries;

        //! Current "editing" ... will be deprecated/removed (use selected instead)
        SceneEntry*                 editing     = nullptr;
        InspectorUI*                properties  = nullptr;
    } m_scene;

    struct {
        const SpatialInfo*          info        = nullptr;
        TypedID                     context;
    } m_spatial;

    FileMode                    m_fileMode  = FileMode::None;
    Flags<F>                    m_flags;
    TypedID                     m_fileIO;
    std::filesystem::path       m_filepath;
    TypedID                     m_controller;
    bool                        m_controllerInit  = false;

    void                        _activate(CameraID);
    void                        _activate(SceneID);
    void                        _activate(RenderedID);

    SceneEntry*                 _add(const Scene&);
    
    void                        _clear();
    SceneEntry*                 _entry(SceneID);
    const SceneEntry*           _entry(SceneID) const;

    void                        _rebuild();
    void                        _title();

    void    _open(const std::filesystem::path&);
    void    _save(const std::filesystem::path&);
    
    void    on_camera_select_event(const CameraSelectEvent&);
    void    on_info_selection_changed_event(const InfoSelectionChangedEvent&);
    void    on_light_select_event(const LightSelectEvent&);
    void    on_load_tsx_reply(const LoadTSXReply&);
    void    on_rendered_select_event(const RenderedSelectEvent&);
    void    on_save_tsx_reply(const SaveTSXReply&);
};

extern TypedID     gFileIO;
