////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>

namespace yq::tachyon {
    class FrameInspectorThreads : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorThreads, FrameInspectorTachyons)
    public:
    
        FrameInspectorThreads() 
        {
        }
        
        ~FrameInspectorThreads()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(THREAD); }
        virtual const char* name() const override { return "Thread"; }

        using FrameInspectorTachyons::render;
        
        void    render(thread_k)
        {
            //const Thread*       thread  = static_cast<const Thread*>(m_tachyon);
            //const ThreadSnap*   snap    = static_cast<const ThreadSnap*>(m_snap);
            const ThreadData*   data    = static_cast<const ThreadData*>(m_data);
        
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> THREAD PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("FPS");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%lf", 1.0 / unit::Second(data->cycleTime).value);
            }

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            bool    treeOpen    = false;
            guard([&](){
                std::string tid    = "objects";
                tid += to_string_view(m_tachyon->id().id);
                treeOpen    = ImGui::TreeNodeEx(tid.c_str(), ImGuiTreeNodeFlags_NoTreePushOnOpen, "Objects");
            });
            ImGui::TableNextColumn();
            ImGui::Text("%ld", data->tachyons.size());

            if(treeOpen){
                end(TABLE);
                ImGui::Indent();

                table_objects();
                
                ImGui::Unindent();
                begin(TABLE);
            }
        }
        
        
        void    render(ViContext&ctx) override
        {
            for(ThreadID v : m_frame->ids(THREAD)){
                if(!begin(v))
                    continue;
                    
                render(THREAD);
                separator();
                render(TACHYON);
                end();
            }
        }

        void    table_objects()
        {
            const ThreadData*   data    = static_cast<const ThreadData*>(m_data);
            
            if(!ImGui::BeginTable("Objects", 3, ImGuiTableFlags_SizingFixedFit))
                return ;
                
            ImGui::TableSetupColumn("ID");
            ImGui::TableSetupColumn("State");
            ImGui::TableSetupColumn("Type");
            ImGui::TableHeadersRow();

            for(const TachyonFrame& tf : data->tachyons){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    ImGui::Text("%ld", tf.object->id().id);
                }
                if(ImGui::TableNextColumn()){
                    switch(tf.state){
                    case TachyonThreadState::Normal:
                        ImGui::TextUnformatted("Normal");
                        break;
                    case TachyonThreadState::Pushed:
                        ImGui::TextUnformatted("Pushed");
                        break;
                    case TachyonThreadState::Delete:
                        ImGui::TextUnformatted("Delete");
                        break;
                    }
                }
                if(ImGui::TableNextColumn()){
                    meta_name(tf.object->metaInfo());
                }
            }
            
            
            ImGui::EndTable();
        }



        static void init_info()
        {
        }
    };
}
