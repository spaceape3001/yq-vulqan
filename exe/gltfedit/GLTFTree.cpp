////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFTree.hpp"
#include <tiny_gltf.h>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/text/join.hpp>
#include <yq/unit/declare.hpp>

namespace {

    std::string gltf_mode(int n)
    {
        switch(n){
        case TINYGLTF_MODE_POINTS:
            return "Points";
        case TINYGLTF_MODE_LINE:
            return "Line";
        case TINYGLTF_MODE_LINE_LOOP:
            return "Line Loop";
        case TINYGLTF_MODE_LINE_STRIP:
            return "Line Strip";
        case TINYGLTF_MODE_TRIANGLES:
            return "Triangles";
        case TINYGLTF_MODE_TRIANGLE_STRIP:
            return "Triangle Strip";
        case TINYGLTF_MODE_TRIANGLE_FAN:
            return "Triangle Fan";
        default:
            return std::format("Unknown mode {}", n);
        }
    }

    std::string gltf_componentType(int n)
    {
        switch(n){
        case TINYGLTF_COMPONENT_TYPE_BYTE:
            return "byte";
        case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
            return "unsigned byte";
        case TINYGLTF_COMPONENT_TYPE_SHORT:
            return "short";
        case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
            return "unsigned short";
        case TINYGLTF_COMPONENT_TYPE_INT:
            return "integer";
        case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
            return "unsigned integer";
        case TINYGLTF_COMPONENT_TYPE_FLOAT:
            return "float";
        case TINYGLTF_COMPONENT_TYPE_DOUBLE:
            return "double";
        default:
            return std::format("Unknown component type {}", n);
        }
    }
    
    std::string gltf_type(int n)
    {
        switch(n){
        case TINYGLTF_TYPE_VEC2:
            return "Vec 2";
        case TINYGLTF_TYPE_VEC3:
            return "Vec 3";
        case TINYGLTF_TYPE_VEC4:
            return "Vec 4";
        case TINYGLTF_TYPE_MAT2:
            return "Mat 2";
        case TINYGLTF_TYPE_MAT3:
            return "Mat 3";
        case TINYGLTF_TYPE_MAT4:
            return "Mat 4";
        case TINYGLTF_TYPE_SCALAR:
            return "Scalar";
        case TINYGLTF_TYPE_VECTOR:
            return "Vector";
        case TINYGLTF_TYPE_MATRIX:
            return "Matrix";
        default:
            return std::format("Unknown type {}", n);
        }
    }
}

void GLTFTree::init_meta()
{
    auto w = writer<GLTFTree>();
    w.description("GLTF Tree");
}

GLTFTree::GLTFTree(UIFlags flags) : UIElement(flags)
{
}

GLTFTree::GLTFTree(const GLTFTree& cp) : UIElement(cp), m_model(cp.m_model)
{
}

GLTFTree::~GLTFTree()
{
}

GLTFTree* GLTFTree::clone() const 
{
    return new GLTFTree(*this);
}


void                    GLTFTree::model(set_k, tinygltf::ModelSPtr v)
{
    m_model = v;
}

tinygltf::ModelSPtr     GLTFTree::model()
{
    return m_model;
}

tinygltf::ModelSCPtr    GLTFTree::model() const
{
    return m_model;
}

void GLTFTree::r_entry(tinygltf::Accessor&a)
{
    using namespace ImGui;

    if(BeginTable("Accessor", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(a.name);
        
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Buffer View");
        if(TableNextColumn())
            Text(a.bufferView);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Byte Offset");
        if(TableNextColumn())
            Text(a.byteOffset);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Components");
        if(TableNextColumn())
            TextUnformatted(gltf_componentType(a.componentType));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Count");
        if(TableNextColumn())
            Text(a.count);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Normalized");
        if(TableNextColumn())
            Text(a.normalized);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Sparse");
        if(TableNextColumn())
            Text(a.sparse.isSparse);


        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Type");
        if(TableNextColumn())
            TextUnformatted(gltf_type(a.type));


        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Animation&a)
{
    using namespace ImGui;

    if(BeginTable("Animation", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(a.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::AudioSource&a)
{
    using namespace ImGui;

    if(BeginTable("AudioSource", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(a.name);

        EndTable();
    }
}
void GLTFTree::r_entry(tinygltf::AudioEmitter&a)
{
    using namespace ImGui;

    if(BeginTable("AudioEmitter", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(a.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Buffer&b)
{
    using namespace ImGui;

    if(BeginTable("Buffer", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(b.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::BufferView&b)
{
    using namespace ImGui;

    if(BeginTable("Buffer View", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(b.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Camera&c)
{
    using namespace ImGui;

    if(BeginTable("Camera", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(c.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Image&i)
{
    using namespace ImGui;

    if(BeginTable("Image", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(i.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Light&l)
{
    using namespace ImGui;

    if(BeginTable("Light", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(l.name);


        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Material&m)
{
    using namespace ImGui;

    if(BeginTable("Material", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(m.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Mesh&m)
{
    using namespace ImGui;

    if(BeginTable("Mesh", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(m.name);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Weights");
        if(TableNextColumn())
            TextUnformatted(join(m.weights, ", "));

        EndTable();
    }

    std::string text    = std::format("Primitives ({})", m.primitives.size());
    if(TreeNode(text.c_str())){
        size_t idx=0;
        for(auto& p : m.primitives){
            text    = std::format("{}##Primitive{}", idx, idx);
            ++idx;
            if(TreeNode(text.c_str())){
                r_entry(p);
                TreePop();
            }
        }
        TreePop();
    }
}

void GLTFTree::r_entry(tinygltf::Model&m)
{
    using namespace ImGui;

    if(BeginTable("Model", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Version");
        if(TableNextColumn())
            TextUnformatted(m.asset.version);
        
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Generator");
        if(TableNextColumn())
            TextUnformatted(m.asset.generator);
        
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Min Version");
        if(TableNextColumn())
            TextUnformatted(m.asset.minVersion);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Copyright");
        if(TableNextColumn())
            TextUnformatted(m.asset.copyright);
        EndTable();
    }
    
}

void GLTFTree::r_entry(tinygltf::Node&n)
{
    using namespace ImGui;

    if(BeginTable("Node", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(n.name);
            
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Camera");
        if(TableNextColumn())
            Text(n.camera);
            
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Children");
        if(TableNextColumn())
            TextUnformatted(join(n.children, ", "));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Emitter");
        if(TableNextColumn())
            Text(n.emitter);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Light");
        if(TableNextColumn())
            Text(n.light);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("LODs");
        if(TableNextColumn())
            TextUnformatted(join(n.lods, ", "));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Matrix");
        if(TableNextColumn())
            TextUnformatted(join(n.matrix, ", "));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Mesh");
        if(TableNextColumn())
            Text(n.mesh);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Rotation");
        if(TableNextColumn())
            TextUnformatted(join(n.rotation, ", "));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Scale");
        if(TableNextColumn())
            TextUnformatted(join(n.scale, ", "));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Skin");
        if(TableNextColumn())
            Text(n.skin);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Translation");
        if(TableNextColumn())
            TextUnformatted(join(n.translation, ", "));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Weights");
        if(TableNextColumn())
            TextUnformatted(join(n.weights, ", "));

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Primitive& p)
{
    using namespace ImGui;
    if(BeginTable("Primitive",2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Material");
        if(TableNextColumn())
            Text(p.material);
        
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Indices (Accessor)");
        if(TableNextColumn())
            Text(p.indices);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Mode");
        if(TableNextColumn())
            TextUnformatted(gltf_mode(p.mode));
        EndTable();
    }
    
    std::string text    = std::format("Accessors ({})", p.attributes.size());
    if(TreeNode(text.c_str())){
        if(BeginTable("Accessors", 2)){
            for(auto& kv : p.attributes){
                TableNextRow();
                if(TableNextColumn())
                    TextUnformatted(kv.first);
                if(TableNextColumn())
                    Text(kv.second);
            }
            EndTable();
        }
        TreePop();
    }
}

void GLTFTree::r_entry(tinygltf::Sampler&s)
{
    using namespace ImGui;

    if(BeginTable("Sampler", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(s.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Scene&s)
{
    using namespace ImGui;

    if(BeginTable("Scene", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(s.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Skin&s)
{
    using namespace ImGui;

    if(BeginTable("Skin", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(s.name);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Texture&t)
{
    using namespace ImGui;

    if(BeginTable("Texture", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(t.name);

        EndTable();
    }
}


void    GLTFTree::render()  
{
    using namespace ImGui;
    if(!m_model){
        TextUnformatted("No Model Loaded");
        return ;
    }
    
    if(TreeNode("Model")){
        r_entry(*m_model);
        TreePop();
    }
    
    Separator();
    
    std::string text;

    text    = std::format("Accessors ({})", m_model->accessors.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& a : m_model->accessors){
            text    = std::format("{}: {}", idx++, a.name);
            if(TreeNode(text.c_str())){
                r_entry(a);
                TreePop();
            }
        }
        TreePop();
    }

    text    = std::format("Animations ({})", m_model->animations.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& a : m_model->animations){
            text    = std::format("{}: {}", idx++, a.name);
            if(TreeNode(text.c_str())){
                r_entry(a);
                TreePop();
            }
        }
        TreePop();
    }

    text    = std::format("Audio Emitters ({})", m_model->audioEmitters.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& a : m_model->audioEmitters){
            text    = std::format("{}: {}", idx++, a.name);
            if(TreeNode(text.c_str())){
                r_entry(a);
                TreePop();
            }
        }
        TreePop();
    }

    text    = std::format("Audio Sources ({})", m_model->audioSources.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& a : m_model->audioSources){
            text    = std::format("{}: {}", idx++, a.name);
            if(TreeNode(text.c_str())){
                r_entry(a);
                TreePop();
            }
        }
        TreePop();
    }

    text    = std::format("Buffers ({})", m_model->buffers.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& b : m_model->buffers){
            text    = std::format("{}: {}", idx++, b.name);
            if(TreeNode(text.c_str())){
                r_entry(b);
                TreePop();
            }
        }
        TreePop();
    }

    text    = std::format("Buffer Views ({})", m_model->bufferViews.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& b : m_model->bufferViews){
            text    = std::format("{}: {}", idx++, b.name);
            if(TreeNode(text.c_str())){
                r_entry(b);
                TreePop();
            }
        }
        TreePop();
    }


    text    = std::format("Cameras ({})", m_model->cameras.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& c : m_model->cameras){
            text    = std::format("{}: {}", idx++, c.name);
            if(TreeNode(text.c_str())){
                r_entry(c);
                TreePop();
            }
        }
        TreePop();
    }

    text    = std::format("Images ({})", m_model->images.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& i : m_model->images){
            text    = std::format("{}: {}", idx++, i.name);
            if(TreeNode(text.c_str())){
                r_entry(i);
                TreePop();
            }
        }
        TreePop();
    }


    text    = std::format("Lights ({})", m_model->lights.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& l : m_model->lights){
            text    = std::format("{}: {}", idx++, l.name);
            if(TreeNode(text.c_str())){
                r_entry(l);
                TreePop();
            }
        }
        
    
        TreePop();
    }

    text    = std::format("Materials ({})", m_model->materials.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& m : m_model->materials){
            text    = std::format("{}: {}", idx++, m.name);
            if(TreeNode(text.c_str())){
                r_entry(m);
                TreePop();
            }
        }
        TreePop();
    }


    text    = std::format("Meshes ({})", m_model->meshes.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& m : m_model->meshes){
            text    = std::format("{}: {}", idx++, m.name);
            if(TreeNode(text.c_str())){
                r_entry(m);
                TreePop();
            }
        }
        TreePop();
    }

    text    = std::format("Nodes ({})", m_model->nodes.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& n : m_model->nodes){
            text    = std::format("{}: {}", idx++, n.name);
            if(TreeNode(text.c_str())){
                r_entry(n);
                TreePop();
            }
        }
        TreePop();
    }


    text    = std::format("Samplers ({})", m_model->samplers.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& s : m_model->samplers){
            text    = std::format("{}: {}", idx++, s.name);
            if(TreeNode(text.c_str())){
                r_entry(s);
                TreePop();
            }
        }

        TreePop();
    }

    text    = std::format("Scenes ({})", m_model->scenes.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& s : m_model->scenes){
            text    = std::format("{}: {}", idx++, s.name);
            if(TreeNode(text.c_str())){
                r_entry(s);
                TreePop();
            }
        }

        TreePop();
    }

    text    = std::format("Skins ({})", m_model->skins.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& s : m_model->skins){
            text    = std::format("{}: {}", idx++, s.name);
            if(TreeNode(text.c_str())){
                r_entry(s);
                TreePop();
            }
        }

        TreePop();
    }

    text    = std::format("Textures ({})", m_model->textures.size());
    if(TreeNode(text.c_str())){
        size_t idx   = 0;
        for(auto& t : m_model->textures){
            text    = std::format("{}: {}", idx++, t.name);
            if(TreeNode(text.c_str())){
                r_entry(t);
                TreePop();
            }
        }
        TreePop();
    }


}

YQ_OBJECT_IMPLEMENT(GLTFTree)
