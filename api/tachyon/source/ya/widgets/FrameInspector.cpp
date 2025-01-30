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

namespace yq::tachyon {
    class FrameInspectorHeader : public FormWidget {
        YQ_TACHYON_DECLARE(FrameInspectorHeader, FormWidget)
    public:
        FrameInspectorHeader() 
        {
        }
        
        ~FrameInspectorHeader()
        {
        }
        
        Execution setup(const Context&ctx) 
        {
            if(m_init)
                return {};
            
            add_row("Number", [this]() -> std::string_view {
                return to_string_view( m_frame -> number() );
            });
            
            add_row("Tick", [this]() -> std::string_view {
                return to_string_view( m_frame -> tick() );
            });
            
            add_row("Origin", [this]() -> std::string_view {
                return to_string_view( m_frame -> origin().id );
            });

            m_init = true;
            return {};
        }
        
        static void init_info()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            m_frame = Frame::current();
            if(!m_frame)
                return ;
            FormWidget::imgui(ctx);
            m_frame = nullptr;
        }
        
    private:
        const Frame*    m_frame = nullptr;
        bool            m_init = false;
    };

    /////////////////////////////////////


    FrameInspector::FrameInspector()
    {
        m_la1   = new TextLabel("Number");
    }
    
    FrameInspector::~FrameInspector()
    {
    }

    Execution FrameInspector::setup(const Context&ctx)
    {
        if(!m_header){
            m_header    = create<FrameInspectorHeader>(CHILD);
        }
        return {};
    }
    
    void    FrameInspector::imgui(ViContext&ctx)
    {
        m_frame     = Frame::current();
        if(ImGui::Begin("FrameInspector")){
            if(!m_frame){
                ImGui::Text("Missing frame");
            } else {
                if(ImGui::TreeNode("Header")){
                    m_header -> imgui(ctx);
                    ImGui::TreePop();
                }
                
                if(ImGui::BeginTable("Frame", 2)){
                
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Cameras");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(CAMERA));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Camera³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(CAMERA³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Controllers");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(CONTROLLER));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Cursors");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(CURSOR));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Desktops");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(DESKTOP));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Keyboards");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(KEYBOARD));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Joysticks");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(JOYSTICK));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Lights");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(LIGHT));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Light³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(LIGHT³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Managers");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(MANAGER));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Models");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(MODEL));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Monitors");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(MONITOR));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Mouses");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(MOUSE));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Rendereds");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(RENDERED));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Rendered³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(RENDERED³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Scenes");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(SCENE));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Scene³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(SCENE³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Spatials");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(SPATIAL));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Spatial³s");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(SPATIAL³));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Tachyons");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(TACHYON));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Threads");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(THREAD));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Viewers");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(VIEWER));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Widgets");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(WIDGET));

                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("Windows");
                    ImGui::TableNextColumn();
                    ImGui::Text("%ld", m_frame->count(WINDOW));

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

YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspector)
YQ_TACHYON_IMPLEMENT(yq::tachyon::FrameInspectorHeader)
