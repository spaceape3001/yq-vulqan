////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIShapePalette.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <yq/text/match.hpp>

using namespace yq;
using namespace yq::tachyon;

struct UIShapePalette::Row {
    std::string_view    iconfile;
    TextureCPtr         icon;
    ImTextureID         tex;
    std::string         label;
    std::string         description;
    const RenderedInfo* info        = nullptr;
};

void UIShapePalette::init_info()
{
    auto w = writer<UIShapePalette>();
    w.description("Table of available shapes/rendereds");
}

UIShapePalette::UIShapePalette(UIFlags flags)
{
}

UIShapePalette::UIShapePalette(const UIShapePalette& cp) : UIElement(cp), m_rows(cp.m_rows)
{
}

UIShapePalette* UIShapePalette::clone() const  
{
    return new UIShapePalette(*this); 
}

const char* UIShapePalette::title() const 
{
    return "Shape Palette";
}

void UIShapePalette::render() 
{
    if(m_rows.empty())
        define_rows();
    if(ImGui::BeginTable("RenderedTypes", 3)){
        //ImGui::TableNextRow();
        //ImGui::TableNextColumn();
        //ImGui::TextUnformatted("icon");
        ////  might get fancy with dynamic rendering... (later)
        //ImGui::TableNextColumn();
        //ImGui::TextUnformatted("name");
        
        Size2F     iconSize = style().icon.def_size;    //< TODO Actual size 
        
        std::string_view    cat;
        for(auto& r : m_rows){
            if(!is_similar(cat, r.info->category())){
                cat = r.info->category();
                ImGui::TableNextRow(ImGuiTableRowFlags_Headers);
                ImGui::TableNextColumn();
                if(ImGui::TableNextColumn())
                    ImGui::TextUnformatted(cat);
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn() && r.tex){
                ImGui::Image(r.tex, iconSize);
            }
            if(ImGui::TableNextColumn()){
                if(ImGui::Selectable(r.label.c_str(), r.info == m_selected)){
                    m_selected  = r.info;
                }
            }
            if(ImGui::TableNextColumn()){
                if(ImGui::Selectable(r.description.c_str(), r.info == m_selected)){
                    m_selected  = r.info;
                }
            }
        }
        
        
        ImGui::EndTable();
    }
}

void        UIShapePalette::define_rows()
{
    for(const RenderedInfo* info : RenderedInfo::all()){
        if(!info)
            continue;
        if(info->is_abstract())
            continue;
        Row     r;
        r.iconfile  = info->icon(BIGGER,48);
        if(r.iconfile.empty())
            r.iconfile  = info->icon(SMALLER,48);
        if(r.iconfile.empty())
            r.iconfile  = style().icon.unknown;
        r.icon  = Texture::load(r.iconfile);
        r.tex   = install(r.icon);
        r.info  = info;
        
        r.label         = std::format("{}##{}", info->stem(), info->name());
        r.description   = std::format("{}##{}", info->description(), info->stem());
        m_rows.push_back(r);
    }
    
    std::stable_sort(m_rows.begin(), m_rows.end(), [](const Row& a, const Row&b){
        Compare cmp = compare_igCase(a.info->category(), b.info->category());
        if(cmp != Compare::EQUAL)
            return is_less(cmp);
        return is_less_igCase(a.label, b.label);
    });
}

YQ_OBJECT_IMPLEMENT(UIShapePalette);
