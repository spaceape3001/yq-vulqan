////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ObjTree.hpp"
//#include <tiny_gltf.h>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/im/KVTable.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/text/match.hpp>
#include <yq/text/join.hpp>
#include <yq/unit/declare.hpp>


void ObjTree::init_meta()
{
    auto w = writer<ObjTree>();
    w.description("Obj Tree");
}

ObjTree::ObjTree(UIFlags flags) : UIElement(flags)
{
}

ObjTree::ObjTree(const ObjTree& cp) : UIElement(cp) //, m_model(cp.m_model)
{
}

ObjTree::~ObjTree()
{
}

ObjTree* ObjTree::clone() const 
{
    return new ObjTree(*this);
}

ObjReaderSPtr    ObjTree::model()
{
    return m_model;
}

ObjReaderSPtr    ObjTree::model() const
{
    return m_model;
}

void             ObjTree::model(set_k, ObjReaderSPtr m, const std::filesystem::path& fp)
{
    m_model = m;
    m_filepath  = fp;
}

void    ObjTree::r_entry(const tinyobj::attrib_t&a)
{
    imgui::KVTable kv;
    kv("Colors") << a.colors.size();
    kv("Normals") << a.normals.size();
    kv("Tex Coords") << a.texcoords.size();
    kv("Tex Coords Ws") << a.texcoord_ws.size();
    kv("Vertex Weights") << a.vertex_weights.size();
    kv("Vertices") << a.vertices.size();
}

void    ObjTree::r_entry(const tinyobj::lines_t& l)
{
    imgui::KVTable kv;
    kv("Indices") << l.indices.size();
    kv("Lines") << l.num_line_vertices.size();
}

void    ObjTree::r_entry(const tinyobj::material_t&m)
{
    imgui::KVTable kv;
    kv("Name") << m.name;
    
    //  and there's a lot here... not required (for now), alter if needed
}

void    ObjTree::r_entry(const tinyobj::mesh_t& m)
{
    using namespace ImGui;

    imgui::KVTable kv;
    kv("Indices") << m.indices.size();
    
    kv("Materials") << !m.material_ids.empty();
    kv("Smoothing Groups") << !m.smoothing_group_ids.empty();

    if(!m.num_face_vertices.empty()){
        kv("Verts Per Face");
        
        auto [mn, mx]   = std::minmax_element(m.num_face_vertices.begin(), m.num_face_vertices.end());
        if(*mn == *mx){
            kv << *mn;
        } else {
            kv << *mn << ".." << *mx;
        }
    }
    kv.finish();
    
    std::string text = std::format("Tags ({})", m.tags.size());
    if(TreeNode(text.c_str())){
        size_t cnt  = 0;
        for(const auto& t : m.tags){
            text    = std::format("{}: {}", cnt++, t.name);
            if(TreeNode(text.c_str())){
                r_entry(t);
                TreePop();
            }
        }
    
        TreePop();
    }
}

void    ObjTree::r_entry(const tinyobj::shape_t&s)
{
    using namespace ImGui;
    
    imgui::KVTable kv;
    kv("Name") << s.name;
    kv("Points") << s.points.indices.size();
    kv.finish();
    
    if(TreeNode("Mesh")){
        r_entry(s.mesh);
        TreePop();
    }
    
    if(TreeNode("Lines")){
        r_entry(s.lines);
        TreePop();
    }
}

void    ObjTree::r_entry(const tinyobj::tag_t& t)
{
    imgui::KVTable kv;
    kv("Name") << t.name;
    kv("Floats") << join(t.floatValues, ",");
    kv("Integers") << join(t.intValues, ",");
    kv("Strings" ) << join(t.stringValues, ",");
}

void    ObjTree::render()  
{
    using namespace ImGui;
    
    if(!m_model){
        TextUnformatted("No Obj file loaded.");
        return ;
    }
    
    imgui::KVTable  kv;
    kv("Wavefront Obj File") << m_filepath;
    kv.finish();
    
    if(TreeNode("Attributes")){
        r_entry(m_model -> GetAttrib());
        TreePop();
    }
    
    std::string text = std::format("Shapes ({})", m_model->GetShapes().size());
    if(TreeNode(text.c_str())){
        size_t  cnt = 0;
        for(const auto& s : m_model->GetShapes()){
            text    = std::format("{}: {}", cnt++, s.name);
            if(TreeNode(text.c_str())){
                r_entry(s);
                TreePop();
            }
        }
    
        TreePop();
    }

    text    = std::format("Materials ({})", m_model->GetMaterials().size());
    if(TreeNode(text.c_str())){
        size_t  cnt = 0;
        for(const auto& m : m_model->GetMaterials()){
            text    = std::format("{}: {}", cnt++, m.name);
            if(TreeNode(text.c_str())){
                r_entry(m);
                TreePop();
            }
        }
        TreePop();
    }
}

YQ_OBJECT_IMPLEMENT(ObjTree)
