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

#include "frame_inspector/FrameInspectorCameras.hpp"
#include "frame_inspector/FrameInspectorCamera3s.hpp"
#include "frame_inspector/FrameInspectorControllers.hpp"
#include "frame_inspector/FrameInspectorCursors.hpp"
#include "frame_inspector/FrameInspectorDesktops.hpp"
#include "frame_inspector/FrameInspectorHeader.hpp"
#include "frame_inspector/FrameInspectorJoysticks.hpp"
#include "frame_inspector/FrameInspectorKeyboards.hpp"
#include "frame_inspector/FrameInspectorLights.hpp"
#include "frame_inspector/FrameInspectorLight3s.hpp"
#include "frame_inspector/FrameInspectorManagers.hpp"
#include "frame_inspector/FrameInspectorModels.hpp"
#include "frame_inspector/FrameInspectorMonitors.hpp"
#include "frame_inspector/FrameInspectorMouses.hpp"
#include "frame_inspector/FrameInspectorRendereds.hpp"
#include "frame_inspector/FrameInspectorRendered3s.hpp"
#include "frame_inspector/FrameInspectorScenes.hpp"
#include "frame_inspector/FrameInspectorScene3s.hpp"
#include "frame_inspector/FrameInspectorSpatials.hpp"
#include "frame_inspector/FrameInspectorSpatial3s.hpp"
#include "frame_inspector/FrameInspectorTachyons.hpp"
#include "frame_inspector/FrameInspectorThreads.hpp"
#include "frame_inspector/FrameInspectorViewers.hpp"
#include "frame_inspector/FrameInspectorWidgets.hpp"
#include "frame_inspector/FrameInspectorWindows.hpp"

namespace yq::tachyon {
    FrameInspector::FrameInspector()
    {
    }
    
    FrameInspector::~FrameInspector()
    {
    }

    Execution FrameInspector::setup(const Context&ctx)
    {
        if(!m_init){
            m_panes.push_back(create<FrameInspectorHeader>(CHILD));
            m_panes.push_back(nullptr);
            m_panes.push_back(create<FrameInspectorCameras>());
            m_panes.push_back(create<FrameInspectorCamera³s>());
            m_panes.push_back(create<FrameInspectorControllers>());
            m_panes.push_back(create<FrameInspectorCursors>());
            m_panes.push_back(create<FrameInspectorDesktops>());
            m_panes.push_back(create<FrameInspectorJoysticks>());
            m_panes.push_back(create<FrameInspectorKeyboards>());
            m_panes.push_back(create<FrameInspectorLights>());
            m_panes.push_back(create<FrameInspectorLight³s>());
            m_panes.push_back(create<FrameInspectorManagers>());
            m_panes.push_back(create<FrameInspectorModels>());
            m_panes.push_back(create<FrameInspectorMonitors>());
            m_panes.push_back(create<FrameInspectorMouses>());
            m_panes.push_back(create<FrameInspectorRendereds>());
            m_panes.push_back(create<FrameInspectorRendered³s>());
            m_panes.push_back(create<FrameInspectorScenes>());
            m_panes.push_back(create<FrameInspectorScene³s>());
            m_panes.push_back(create<FrameInspectorSpatials>());
            m_panes.push_back(create<FrameInspectorSpatial³s>());
            m_panes.push_back(create<FrameInspectorTachyons>());
            m_panes.push_back(create<FrameInspectorThreads>());
            m_panes.push_back(create<FrameInspectorViewers>());
            m_panes.push_back(create<FrameInspectorWidgets>());
            m_panes.push_back(create<FrameInspectorWindows>());
            m_init  = true;
        }
        return {};
    }
    
    void    FrameInspector::imgui(ViContext&ctx)
    {
        //  Need to add in a "hold" flag...
        if(m_track){
            m_frame     = Frame::current();
            for(Pane* s : m_panes){
                if(!s)
                    continue;
                s->set_frame(m_frame.ptr());
            }
        }
        
        if(ImGui::Begin("FrameInspector")){
            ImGui::ToggleButton("Track", &m_track);
        
            if(!m_frame){
                ImGui::Text("Missing frame");
            } else {
                for(Pane* p : m_panes){
                    if(!p){
                        ImGui::Separator();
                        continue;
                    }
                    
                    bool    tree = false;
                    if(p->countable()){
                        tree    = ImGui::TreeNode(p->name(), "%s (%ld)", p->name(), p->count());
                    } else {
                        tree    = ImGui::TreeNode(p->name());
                    }
                    if(tree){
                        p->render(ctx);
                        ImGui::TreePop();
                    }
                }
            }
        }
        ImGui::End();
    }
    
    void FrameInspector::init_info()
    {
        auto w = writer<FrameInspector>();
        w.description("Frame Inspector");
        w.imgui();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspector)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorHeader)
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
