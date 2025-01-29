////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/widgets/FrameInspector.hpp>
#include <ya/minis/TextLabel.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>
#include <yt/api/Frame.hpp>
#include <yt/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspector)

namespace yq::tachyon {
    FrameInspector::FrameInspector()
    {
        m_la1   = new TextLabel("Number");
    }
    
    FrameInspector::~FrameInspector()
    {
    }
    
    void    FrameInspector::imgui(ViContext&ctx)
    {
        if(ImGui::Begin("FrameInspector")){
            const Frame*  frame = Frame::current();
            if(!frame){
                ImGui::Text("Missing frame");
            } else {
                
                if(ImGui::BeginTable("Frame", 2)){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    m_la1->imgui(ctx);
//                    ImGui::Text("Number");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->number());

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Tick");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->tick());
                    
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::TableSetColumnIndex(0);
                    ImGui::Text("Origin");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->origin().id);

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Cameras");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(CAMERA));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Camera³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(CAMERA³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Controllers");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(CONTROLLER));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Cursors");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(CURSOR));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Desktops");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(DESKTOP));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Keyboards");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(KEYBOARD));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Joysticks");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(JOYSTICK));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Lights");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(LIGHT));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Light³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(LIGHT³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Managers");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(MANAGER));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Models");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(MODEL));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Monitors");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(MONITOR));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Mouses");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(MOUSE));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Rendereds");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(RENDERED));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Rendered³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(RENDERED³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Scenes");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(SCENE));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Scene³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(SCENE³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Spatials");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(SPATIAL));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Spatial³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(SPATIAL³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Tachyons");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(TACHYON));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Threads");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(THREAD));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Viewers");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(VIEWER));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Widgets");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(WIDGET));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Windows");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", frame->count(WINDOW));

                    ImGui::EndTable();
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
