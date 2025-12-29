////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/im/text.hpp>

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
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> THREAD PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("FPS");
            }
            if(ImGui::TableNextColumn()){
                im::text(1.0 / unit::Second(data->cycleTime));
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
            im::text(data->tachyons.size());

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
                    im::text(tf.object->id());
                }
                if(ImGui::TableNextColumn()){
                    switch(tf.state){
                    case TachyonThreadState::Normal:
                        im::text("Normal");
                        break;
                    case TachyonThreadState::Pushed:
                        im::text("Pushed");
                        break;
                    case TachyonThreadState::Delete:
                        im::text("Delete");
                        break;
                    }
                }
                if(ImGui::TableNextColumn()){
                    meta_name(tf.object->metaInfo());
                }
            }
            
            
            ImGui::EndTable();
        }



        static void init_meta()
        {
        }
    };
}
