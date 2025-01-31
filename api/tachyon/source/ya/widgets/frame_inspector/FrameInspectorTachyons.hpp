////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>
#include <ya/widgets/FrameInspector.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/api/Thread.hpp>

namespace yq::tachyon {
    class FrameInspectorTachyons : public Widget, public FrameInspector::Pane {
        YQ_TACHYON_DECLARE(FrameInspectorTachyons, Widget)
    public:

        using FrameInspector::Pane::render;
    
        FrameInspectorTachyons() 
        {
        }
        
        ~FrameInspectorTachyons()
        {
        }
        
        static void init_info()
        {
        }

        bool    begin(TachyonID tid)
        {
            set(tid);
            if(!m_tachyon)
                return false;
            
            std::string_view    mn  = m_tachyon->metaInfo().name();
            m_tree = ImGui::TreeNode((const void*) tid.id, "%.*s {%ld}", (int) mn.size(), mn.data(), tid.id);
            if(!m_tree)
                return false;

            std::string nid = to_string(tid.id);
            m_table = ImGui::BeginTable(nid.c_str(), 2);
            return m_table;
        }
        
        size_t count() const override 
        { 
            return m_frame->count(TACHYON); 
        }

        bool countable() const override 
        { 
            return true; 
        }
        
        void    end()
        {
            if(m_table){
                ImGui::EndTable();
                m_table = false;
            }
            if(m_tree){
                ImGui::TreePop();
                m_tree  = false;
            }
        }


        void    meta_id(TachyonID tid)
        {
            if(!tid){
                ImGui::Text("(none) {0}");
                return;
            }
        
            if(!m_frame){
                ImGui::Text("(no-frame) {%ld}", tid.id);
                return;
            }
            
            const Tachyon*  t   = m_frame->object(tid);
            if(!m_frame){
                ImGui::Text("(missing) {%ld}", tid.id);
                return;
            }
            
            std::string_view    mn  = t->metaInfo().name();
            ImGui::Text("%.*s {%ld}", (int) mn.size(), mn.data(), tid.id);
        }
        
        void    meta_name(const ObjectInfo& objInfo)
        {
            std::string_view    mn  = objInfo.name();
            ImGui::Text("%.*s", (int) mn.size(), mn.data());
        }
        
        const char* name() const override { return "Tachyon"; }
        
        void    render(tachyon_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Cycle Time (ns)");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%lf", m_data->cycleTime.value);
            }

            if(ImGui::TreeNode("Inbound", "Inbound (%ld)", m_data->inbound.size())){
                if(ImGui::BeginTable("InPosts", 5)){
                    
                    ImGui::TableHeadersRow();
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("ID");
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("Type");
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("Source");
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("Target");
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("State");
                    
                    for(const InPost& ip : m_data->inbound){
                        ImGui::TableNextRow();

                        if(!ip.post){
                            ImGui::TableNextColumn();
                            ImGui::TextUnformatted("(null)");
                            continue;
                        }
                            
                        if(ImGui::TableNextColumn()){
                            ImGui::Text("%ld", ip.post->id().id);
                        }
                        if(ImGui::TableNextColumn()){
                            meta_name(ip.post->metaInfo());
                        }
                        if(ImGui::TableNextColumn()){
                            meta_id(ip.post->source());
                        }
                        if(ImGui::TableNextColumn()){
                            meta_id(ip.post->target());
                        }
                        if(ImGui::TableNextColumn()){
                            switch(ip.state){
                            case InPost::State::Accepted:
                                ImGui::TextUnformatted("Accepted");
                                break;
                            case InPost::State::Rejected:
                                ImGui::TextUnformatted("Rejected");
                                break;
                            case InPost::State::Duplicate:
                                ImGui::TextUnformatted("Duplicate");
                                break;
                            }
                        }
                    }
                
                    ImGui::EndTable();
                }
            
                ImGui::TreePop();
            }
        
            if(ImGui::TreeNode("Outbound", "Outbound (%ld)", m_data->outbound.size())){
                if(ImGui::BeginTable("OutPosts", 4)){
                    
                    ImGui::TableHeadersRow();
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("ID");
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("Type");
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("Source");
                    ImGui::TableNextColumn();
                    ImGui::TextUnformatted("Target");
                    
                    for(const OutPost& op : m_data->outbound){
                        ImGui::TableNextRow();
                        if(!op.post){
                            ImGui::TableNextColumn();
                            ImGui::TextUnformatted("(null)");
                            continue;
                        }
                        if(ImGui::TableNextColumn()){
                            ImGui::Text("%ld", op.post->id().id);
                        }
                        if(ImGui::TableNextColumn()){
                            meta_name(op.post->metaInfo());
                        }
                        if(ImGui::TableNextColumn()){
                            meta_id(op.post->source());
                        }
                        if(ImGui::TableNextColumn()){
                            meta_id(op.post->target());
                        }
                    }
                
                    ImGui::EndTable();
                }
            
                ImGui::TreePop();
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Owner");
            }
            if(ImGui::TableNextColumn()){
                meta_id(m_data->owner);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Parent");
            }
            if(ImGui::TableNextColumn()){
                meta_id(m_snap->parent);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Stage");
            }
            if(ImGui::TableNextColumn()){
                if(m_snap->started){
                    ImGui::TextUnformatted("Started");
                }
                if(m_snap->running){
                    ImGui::TextUnformatted(", Running");
                }
                if(m_snap->paused){
                    ImGui::TextUnformatted(", Paused");
                }
                if(m_snap->teardown){
                    ImGui::TextUnformatted(", Teardown");
                }
            }
        }
    
        void    render(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(TachyonID v : m_frame->ids(TACHYON)){
                if(begin(v)){
                    render(TACHYON);
                    end();
                }
            }
        }
        
        void    set(TachyonID tid) 
        {
            if(m_frame){
                m_snap      = m_frame->snap(tid);
                m_data      = m_frame->data(tid);
                m_tachyon   = m_frame->object(tid);
            }
        }

        //const char*     imgui_id() const override
        //{
            //return m_imguiID.c_str();
        //}
        
    protected:
        const TachyonSnap*      m_snap      = nullptr;
        const TachyonData*      m_data      = nullptr;
        const Tachyon*          m_tachyon   = nullptr;
    private:
        bool                    m_init      = false;
        bool                    m_table     = false;
        bool                    m_tree      = false;
        std::string             m_imguiID;
    };
}
