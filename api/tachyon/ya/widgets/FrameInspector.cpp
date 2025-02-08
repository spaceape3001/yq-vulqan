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

#include "imgui_internal.h"

#include "frame_inspector/FrameInspectorCameras.hpp"
#include "frame_inspector/FrameInspectorCamera3s.hpp"
#include "frame_inspector/FrameInspectorControllers.hpp"
#include "frame_inspector/FrameInspectorCursors.hpp"
#include "frame_inspector/FrameInspectorDesktops.hpp"
#include "frame_inspector/FrameInspectorGamepads.hpp"
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
    yInfo() << "FrameInspector::FrameInspector()";
    }
    
    FrameInspector::~FrameInspector()
    {
    yInfo() << "FrameInspector::~FrameInspector()";
    }

    template <typename Pred>
    void      FrameInspector::guard(Pred&& pred)
    {
        auto &id_stack = ImGui::GetCurrentWindow()->IDStack;
        const auto outer_table_instance_id  = id_stack.back();
        id_stack.pop_back();
        pred();
        id_stack.push_back(outer_table_instance_id);
    }

    Execution FrameInspector::setup(const Context&ctx)
    {
        if(!m_init){
            m_panes.push_back(create_child<FrameInspectorHeader>());
            m_panes.push_back(nullptr);
            m_panes.push_back(create_child<FrameInspectorCameras>());
            m_panes.push_back(create_child<FrameInspectorCamera³s>());
            m_panes.push_back(create_child<FrameInspectorControllers>());
            m_panes.push_back(create_child<FrameInspectorCursors>());
            m_panes.push_back(create_child<FrameInspectorDesktops>());
            m_panes.push_back(create_child<FrameInspectorGamepads>());
            m_panes.push_back(create_child<FrameInspectorJoysticks>());
            m_panes.push_back(create_child<FrameInspectorKeyboards>());
            m_panes.push_back(create_child<FrameInspectorLights>());
            m_panes.push_back(create_child<FrameInspectorLight³s>());
            m_panes.push_back(create_child<FrameInspectorManagers>());
            m_panes.push_back(create_child<FrameInspectorModels>());
            m_panes.push_back(create_child<FrameInspectorMonitors>());
            m_panes.push_back(create_child<FrameInspectorMouses>());
            m_panes.push_back(create_child<FrameInspectorRendereds>());
            m_panes.push_back(create_child<FrameInspectorRendered³s>());
            m_panes.push_back(create_child<FrameInspectorScenes>());
            m_panes.push_back(create_child<FrameInspectorScene³s>());
            m_panes.push_back(create_child<FrameInspectorSpatials>());
            m_panes.push_back(create_child<FrameInspectorSpatial³s>());
            m_panes.push_back(create_child<FrameInspectorTachyons>());
            m_panes.push_back(create_child<FrameInspectorThreads>());
            m_panes.push_back(create_child<FrameInspectorViewers>());
            m_panes.push_back(create_child<FrameInspectorWidgets>());
            m_panes.push_back(create_child<FrameInspectorWindows>());
            
            for(Pane* p : m_panes){
                if(!p)
                    continue;
                p->m_inspector  = this;
            }
            
            m_init  = true;
        }
        return Widget::setup(ctx);
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
            } else if((m_table = ImGui::BeginTable(szTable, nTableCols, ImGuiTableFlags_NoClip))){
                ImGui::TableSetupColumn("Key", 
                    ImGuiTableColumnFlags_IndentEnable | 
                    ImGuiTableColumnFlags_NoSort | ImGuiTableColumnFlags_WidthStretch, 0.20 );
                ImGui::TableSetupColumn("Value", 
                    ImGuiTableColumnFlags_IndentDisable | ImGuiTableColumnFlags_NoClip |
                    ImGuiTableColumnFlags_NoSort | ImGuiTableColumnFlags_WidthStretch, 0.80 );
            
                for(Pane* p : m_panes){
                    if(!table_begin())
                        continue;

                    ImGui::TableNextRow();
                    if(!p){
                        ImGui::Separator();
                        continue;
                    }
                    ImGui::TableNextColumn();

                    bool    treeOpen = false;
                    guard([&](){
                        treeOpen    = ImGui::TreeNodeEx(p->name(), ImGuiTreeNodeFlags_NoTreePushOnOpen);
                    });

                    ImGui::TableNextColumn();
                    if(p->countable()){
                        ImGui::Text("%ld", p->count());
                    }
                    
                    if(treeOpen){
                        ImGui::Indent();
                        p->render(ctx);
                        ImGui::Unindent();
                    }
                }

                if(m_table){
                    ImGui::EndTable();
                }
            }
        }
        ImGui::End();
    }

    bool FrameInspector::table_begin()
    {
        if(!m_table){
            ImGui::Unindent();
            m_table = ImGui::BeginTable(szTable, nTableCols, ImGuiTableFlags_SizingFixedFit|ImGuiTableFlags_NoClip);
        }
        return m_table;
    }
    
    void FrameInspector::table_end()
    {
        if(m_table){
            ImGui::EndTable();
            ImGui::Indent();
            m_table = false;
        }
    }
    
    void FrameInspector::init_info()
    {
        auto w = writer<FrameInspector>();
        w.description("Frame Inspector");
        w.imgui();
    }
    
    ///////////////////////////////////
    
    
    bool    FrameInspector::Pane::begin(table_k)
    {
        if(m_inspector)
            return m_inspector->table_begin();
        return false;
    }
    
    
    void    FrameInspector::Pane::end(table_k)
    {
        if(m_inspector)
            m_inspector->table_end();
    }
    
    template <typename Pred>
    void    FrameInspector::Pane::guard(Pred&&pred)
    {
        if(m_inspector){
            m_inspector->guard<Pred>(std::move(pred));
        }
    }

}

YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspector)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorHeader)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorCameras)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorCamera³s)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorControllers)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorCursors)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorDesktops)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorGamepads)
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
