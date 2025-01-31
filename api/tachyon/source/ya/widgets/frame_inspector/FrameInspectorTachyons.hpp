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
#include <yq/unit/literals.hpp>
#include <yq/text/join.hpp>

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
        
        using FrameInspector::Pane::begin;

        bool    begin(TachyonID tid)
        {
            set(tid);
            if(!m_tachyon)
                return false;

            std::string nid = name();
            nid += '.';
            nid += to_string_view(tid.id);

            ImGui::TableNextRow();
            ImGui::TableNextColumn();

            guard([&](){
                m_tree  = ImGui::TreeNodeEx(nid.c_str(), ImGuiTreeNodeFlags_NoTreePushOnOpen, "%ld", tid.id);
            });

            ImGui::TableNextColumn();
            ImGui::TextUnformatted(m_tachyon->metaInfo().name());
            if(m_tree){
                ImGui::Indent();
            }
            return m_tree;
        }
        
        size_t count() const override 
        { 
            return m_frame->count(TACHYON); 
        }

        bool countable() const override 
        { 
            return true; 
        }
        
        using FrameInspector::Pane::end;
        
        void    end()
        {
            begin(TABLE);
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            ImGui::TableNextColumn();
            
            if(m_tree){
                ImGui::Unindent();
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

        void    meta_name(TachyonID tid)
        {
            if(!tid){
                ImGui::TextUnformatted("(none)");
                return;
            }
        
            if(!m_frame){
                ImGui::TextUnformatted("(no-frame)");
                return;
            }
            
            const Tachyon*  t   = m_frame->object(tid);
            if(!m_frame){
                ImGui::TextUnformatted("(missing)");
                return;
            }
            
            meta_name(t->metaInfo());
        }
        
        const char* name() const override { return "Tachyon"; }
        
        void    render(tachyon_k)
        {
            bool    treeOpen    = false;

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> TACHYON PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            guard([&](){
                std::string tid    = "children";
                tid += to_string_view(m_tachyon->id().id);
                treeOpen    = ImGui::TreeNodeEx(tid.c_str(), ImGuiTreeNodeFlags_NoTreePushOnOpen, "Children");
            });
            ImGui::TableNextColumn();
            ImGui::Text("%ld", m_snap->children.size());

            if(treeOpen){
                end(TABLE);
                ImGui::Indent();

                table_children();
                
                ImGui::Unindent();
                begin(TABLE);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Cycle");
            }
            if(ImGui::TableNextColumn()){
                if(m_data->cycleTime < 1_µs){
                    ImGui::Text("%lf ns", m_data->cycleTime.value);
                } else if(m_data->cycleTime < 1_ms){
                    ImGui::Text("%lf µs", unit::Microsecond(m_data->cycleTime).value);
                } else if(m_data->cycleTime < 1_s){
                    ImGui::Text("%lf ms", unit::Millisecond(m_data->cycleTime).value);
                } else {
                    ImGui::Text("%lf s",  unit::Second(m_data->cycleTime).value);
                }
            }
            
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            guard([&](){
                std::string tid    = "inbound";
                tid += to_string_view(m_tachyon->id().id);
                treeOpen    = ImGui::TreeNodeEx(tid.c_str(), ImGuiTreeNodeFlags_NoTreePushOnOpen, "Inbound");
            });
            ImGui::TableNextColumn();
            ImGui::Text("%ld", m_data->inbound.size());

            if(treeOpen){
                end(TABLE);
                ImGui::Indent();

                table_inbound();
                
                ImGui::Unindent();
                begin(TABLE);
            }
        
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            guard([&](){
                std::string tid    = "outbound";
                tid += to_string_view(m_tachyon->id().id);
                treeOpen    = ImGui::TreeNodeEx(tid.c_str(), ImGuiTreeNodeFlags_NoTreePushOnOpen, "Outbound");
            });
            ImGui::TableNextColumn();
            ImGui::Text("%ld", m_data->outbound.size());

            if(treeOpen){
                end(TABLE);
                ImGui::Indent();

                table_outbound();
                
                ImGui::Unindent();
                begin(TABLE);
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
                ImGui::TextUnformatted("Proxies");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", m_snap->proxies.size());
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Revision");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", m_snap->revision);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Stage");
            }
            if(ImGui::TableNextColumn()){
                std::string msg;
                if(m_snap->started){
                    msg = "Started";
                }
                if(m_snap->running){
                    msg += ", Running";
                }
                if(m_snap->paused){
                    msg += ", Paused";
                }
                if(m_snap->teardown){
                    msg += ", Teardown";
                }
                ImGui::TextUnformatted(msg.c_str());
            }
        }
        
        void    separator()
        {
            ImGui::TableNextRow();
            ImGui::Separator();
        }
    
        void    render(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(TachyonID v : m_frame->ids(TACHYON)){
                if(!begin(v))
                    continue;

                render(TACHYON);
                end();
            }
        }
        
        void    table_children()
        {
            if(!ImGui::BeginTable("Children", 2, ImGuiTableFlags_SizingFixedFit))
                return ;
            
            ImGui::TableSetupColumn("ID");
            ImGui::TableSetupColumn("Type");
            ImGui::TableHeadersRow();
            
            for(const TypedID& t : m_snap->children){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    ImGui::Text("%ld", t.id);
                }
                if(ImGui::TableNextColumn()){
                    meta_name(t);
                }
            }
            
            ImGui::EndTable();
        }
        
        void    table_inbound() 
        {
            if(!ImGui::BeginTable("InPosts", 5, ImGuiTableFlags_SizingFixedFit))
                return ;
                
            ImGui::TableSetupColumn("ID");
            ImGui::TableSetupColumn("Type");
            ImGui::TableSetupColumn("Source");
            ImGui::TableSetupColumn("Target");
            ImGui::TableSetupColumn("State");
            ImGui::TableHeadersRow();
            
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
        
        void    table_outbound()
        {
            if(!ImGui::BeginTable("OutPosts", 4, ImGuiTableFlags_SizingFixedFit))
                return ;

            ImGui::TableSetupColumn("ID");
            ImGui::TableSetupColumn("Type");
            ImGui::TableSetupColumn("Source");
            ImGui::TableSetupColumn("Target");
            ImGui::TableHeadersRow();
            
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
        bool                    m_tree      = false;
        std::string             m_imguiID;
    };
}
