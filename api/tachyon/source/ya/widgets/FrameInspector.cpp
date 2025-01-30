////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/widgets/FormWidget.hpp>
#include <ya/widgets/FrameInspector.hpp>
#include <ya/minis/TextLabel.hpp>
#include <yq/text/format.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>
#include <yt/api/Frame.hpp>
#include <yt/logging.hpp>

#include "frame_inspector/FrameInspectorSub.hpp"
#include "frame_inspector/FrameInspectorHeader.ipp"
#include "frame_inspector/FrameInspectorPane.ipp"

#include "frame_inspector/FrameInspectorCameras.ipp"
#include "frame_inspector/FrameInspectorCamera3s.ipp"
#include "frame_inspector/FrameInspectorControllers.ipp"
#include "frame_inspector/FrameInspectorCursors.ipp"
#include "frame_inspector/FrameInspectorDesktops.ipp"
#include "frame_inspector/FrameInspectorJoysticks.ipp"
#include "frame_inspector/FrameInspectorKeyboards.ipp"
#include "frame_inspector/FrameInspectorLights.ipp"
#include "frame_inspector/FrameInspectorLight3s.ipp"
#include "frame_inspector/FrameInspectorManagers.ipp"
#include "frame_inspector/FrameInspectorModels.ipp"
#include "frame_inspector/FrameInspectorMonitors.ipp"
#include "frame_inspector/FrameInspectorMouses.ipp"
#include "frame_inspector/FrameInspectorRendereds.ipp"
#include "frame_inspector/FrameInspectorRendered3s.ipp"
#include "frame_inspector/FrameInspectorScenes.ipp"
#include "frame_inspector/FrameInspectorScene3s.ipp"
#include "frame_inspector/FrameInspectorSpatials.ipp"
#include "frame_inspector/FrameInspectorSpatial3s.ipp"
#include "frame_inspector/FrameInspectorTachyons.ipp"
#include "frame_inspector/FrameInspectorThreads.ipp"
#include "frame_inspector/FrameInspectorViewers.ipp"
#include "frame_inspector/FrameInspectorWidgets.ipp"
#include "frame_inspector/FrameInspectorWindows.ipp"

namespace yq::tachyon {




    /////////////////////////////////////


    FrameInspector::FrameInspector()
    {
    }
    
    FrameInspector::~FrameInspector()
    {
    }

    template <typename F>
    void      FrameInspector::make(Widget*&w)
    {
        if(!w){
            auto p  = create<F>(CHILD);
            w       = p;
            m_subs.push_back(p);
        }
    }

    Execution FrameInspector::setup(const Context&ctx)
    {
        make<FrameInspectorHeader>(m_header);
        make<FrameInspectorCameras>(m_cameras);
        make<FrameInspectorCamera³s>(m_camera³s);
        make<FrameInspectorControllers>(m_controllers);
        make<FrameInspectorCursors>(m_cursors);
        make<FrameInspectorDesktops>(m_desktops);
        make<FrameInspectorJoysticks>(m_joysticks);
        make<FrameInspectorKeyboards>(m_keyboards);
        make<FrameInspectorLights>(m_lights);
        make<FrameInspectorLight³s>(m_light³s);
        make<FrameInspectorManagers>(m_managers);
        make<FrameInspectorModels>(m_models);
        make<FrameInspectorMonitors>(m_monitors);
        make<FrameInspectorMouses>(m_mouses);
        make<FrameInspectorRendereds>(m_rendereds);
        make<FrameInspectorRendered³s>(m_rendered³s);
        make<FrameInspectorScenes>(m_scenes);
        make<FrameInspectorScene³s>(m_scene³s);
        make<FrameInspectorSpatials>(m_spatials);
        make<FrameInspectorSpatial³s>(m_spatial³s);
        make<FrameInspectorTachyons>(m_tachyons);
        make<FrameInspectorThreads>(m_threads);
        make<FrameInspectorViewers>(m_viewers);
        make<FrameInspectorWidgets>(m_widgets);
        make<FrameInspectorWindows>(m_windows);
        return {};
    }
    
    void    FrameInspector::imgui(ViContext&ctx)
    {
        //  Need to add in a "hold" flag...
        if(m_track){
            m_frame     = Frame::current();
            for(Sub* s : m_subs){
                s->set_frame(m_frame.ptr());
            }
        }
        
        if(ImGui::Begin("FrameInspector")){
            ImGui::ToggleButton("Track", &m_track);
        
            if(!m_frame){
                ImGui::Text("Missing frame");
            } else {
                if(ImGui::TreeNode("Header")){
                    m_header -> imgui(ctx);
                    ImGui::TreePop();
                }
                
                ImGui::Separator();
                
                if(ImGui::TreeNode("Camera", "Camera (%ld)", m_frame->count(CAMERA))){
                    m_cameras -> imgui(ctx);
                    ImGui::TreePop();
                }
                
                if(ImGui::TreeNode("Camera3", "Camera³ (%ld)", m_frame->count(CAMERA³))){
                    m_camera³s -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Controller", "Controller (%ld)", m_frame->count(CONTROLLER))){
                    m_controllers -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Cursor", "Cursor (%ld)", m_frame->count(CURSOR))){
                    m_cursors -> imgui(ctx);
                    ImGui::TreePop();
                }
                
                if(ImGui::TreeNode("Desktop", "Desktop (%ld)", m_frame->count(DESKTOP))){
                    m_desktops -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Joystick", "Joystick (%ld)", m_frame->count(JOYSTICK))){
                    m_joysticks -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Keyboard", "Keyboard (%ld)", m_frame->count(KEYBOARD))){
                    m_keyboards -> imgui(ctx);
                    ImGui::TreePop();
                }


                if(ImGui::TreeNode("Light", "Light (%ld)", m_frame->count(LIGHT))){
                    m_lights -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Light3", "Light³ (%ld)", m_frame->count(LIGHT³))){
                    m_light³s -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Manager", "Manager (%ld)", m_frame->count(MANAGER))){
                    m_managers -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Model", "Model (%ld)", m_frame->count(MODEL))){
                    m_models -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Monitor", "Monitor (%ld)", m_frame->count(MONITOR))){
                    m_monitors -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Mouse", "Mouse (%ld)", m_frame->count(MOUSE))){
                    m_mouses -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Rendered", "Rendered (%ld)", m_frame->count(RENDERED))){
                    m_rendereds -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Rendered3", "Rendered³ (%ld)", m_frame->count(RENDERED³))){
                    m_rendered³s -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Scene", "Scene (%ld)", m_frame->count(SCENE))){
                    m_scenes -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Scene3", "Scene³ (%ld)", m_frame->count(SCENE³))){
                    m_scene³s -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Spatial", "Spatial (%ld)", m_frame->count(SPATIAL))){
                    m_spatials -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Spatial3", "Spatial³ (%ld)", m_frame->count(SPATIAL³))){
                    m_spatial³s -> imgui(ctx);
                    ImGui::TreePop();
                }
                if(ImGui::TreeNode("Tachyon", "Tachyon (%ld)", m_frame->count(TACHYON))){
                    m_tachyons -> imgui(ctx);
                    ImGui::TreePop();
                }
                if(ImGui::TreeNode("Thread", "Thread (%ld)", m_frame->count(THREAD))){
                    m_threads -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Viewer", "Viewer (%ld)", m_frame->count(VIEWER))){
                    m_viewers -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Widget", "Widget (%ld)", m_frame->count(WIDGET))){
                    m_widgets -> imgui(ctx);
                    ImGui::TreePop();
                }

                if(ImGui::TreeNode("Window", "Window (%ld)", m_frame->count(WINDOW))){
                    m_windows -> imgui(ctx);
                    ImGui::TreePop();
                }
            }
        }
        ImGui::End();
    }
    
    void FrameInspector::init_info()
    {
        auto w = writer<FrameInspector>();
        w.imgui();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspector)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorHeader)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorPane)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorCameras)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorCamera³s)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorControllers)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorCursors)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorDesktops)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorJoysticks)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorKeyboards)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorLights)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorLight³s)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorManagers)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorModels)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorMonitors)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorMouses)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorRendereds)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorRendered³s)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorScenes)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorScene³s)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorSpatials)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorSpatial³s)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorTachyons)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorThreads)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorViewers)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorWidgets)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorWindows)
