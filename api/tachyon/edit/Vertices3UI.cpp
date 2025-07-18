////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Vertices3UI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorMetaWriter.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <tachyon/proxy/PVertices3.hpp>
#include <yq/math/UV.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Vertices³UI)

namespace yq::tachyon {
    void Vertices³UI::init_meta()
    {
        auto w = writer<Vertices³UI>();
        w.description("UIEditor for Vertices³");
        w.edits<PVertices³>();
        w.field("Vertex", &Vertices³UI::vertices);
    }
    
    Vertices³UI::Vertices³UI(UIFlags flags)
    {
    }
    
    Vertices³UI::Vertices³UI(const Vertices³UI& cp) : UIEditor(cp)
    {
    }
    
    Vertices³UI* Vertices³UI::clone() const
    {
        return new Vertices³UI(*this);
    }

    void    Vertices³UI::vertices()
    {
        PVertices³* p   = snap()->proxy<PVertices³>();
        if(!p)
            return ;
        
        //bool    erasable    = p->vertices(ERASABLE);
        //bool    insertable  = p->vertices(INSERTABLE);
        //bool    appendable  = p->vertices(APPENDABLE);
        bool    color       = p->vertices(COLOR);
        bool    texs        = p->vertices(TEX);
        bool    normals     = p->vertices(NORMAL);
        size_t  count       = p->vertices(COUNT);
        
        int     numCols     = 2;
        //if(erasable)
        //    ++numCols;
        //if(insertable)
        //    ++numCols;
        if(color)
            ++numCols;
        if(texs)
            ++numCols;
        if(normals)
            ++numCols;
            
        ImGui::InputDoubleOptions  vertOpts{.format="%.3lf"};
        ImGui::InputFloatOptions   uvOpts;
        ImGui::InputFloatOptions   normalOpts;
        ImGuiColorEditFlags colorFlags  = 0;
        
        
        if(!p->vertices(SETTABLE, POINT))
            vertOpts.flags |= ImGuiInputTextFlags_ReadOnly;
        if(!p->vertices(SETTABLE, TEX))
            uvOpts.flags |= ImGuiInputTextFlags_ReadOnly;
        if(!p->vertices(SETTABLE, NORMAL))
            normalOpts.flags |= ImGuiInputTextFlags_ReadOnly;
        if(!p->vertices(SETTABLE, COLOR)){
            colorFlags |= ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoPicker;
        }
            
        std::string     tableId = std::format("##Vertices³UI{}", bound().id);
        if(ImGui::BeginTable(tableId.c_str(), numCols)){
            
            //  setup columns... TODO....
            ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthFixed, style().table.idcol() );
            ImGui::TableSetupColumn("Point");
            if(texs)
                ImGui::TableSetupColumn("Tex");
            if(texs)
                ImGui::TableSetupColumn("Normal");
            ImGui::TableHeadersRow();
            
            for(size_t n=1;n<=count;++n){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    ImGui::Text(n);
                }
                if(ImGui::TableNextColumn()){
                    std::string id = std::format("##Vertex{}.{}", bound().id, n);
                    Vector3D    v   = p->vertex(n, POINT);
                    if(ImGui::Input(id.c_str(), v, vertOpts)){
                        p->vertex(n, SET, POINT, v);
                    }
                }
                if(texs && ImGui::TableNextColumn()){
                    std::string id = std::format("##TexUV{}.{}", bound().id, n);
                    UV2F        v   = p->vertex(n, TEX);
                    if(ImGui::Input(id.c_str(), v, uvOpts)){
                        p->vertex(n, SET, TEX, v);
                    }
                }
                if(normals && ImGui::TableNextColumn()){
                    std::string id = std::format("##Normal{}.{}", bound().id, n);
                    Vector3F    v   = p->vertex(n, NORMAL);
                    if(ImGui::Input(id.c_str(), v, normalOpts)){
                        p->vertex(n, SET, NORMAL, v);
                    }
                }
                if(color && ImGui::TableNextColumn()){
                    std::string id = std::format("##Color{}.{}", bound().id, n);
                    RGBA4F  v   = p->vertex(n, COLOR);
                    if(ImGui::ColorEdit(id.c_str(), v, colorFlags)){
                        p->vertex(n, SET, COLOR, v);
                    }
                }
            }
            
            ImGui::EndTable();
        }
    }
}
