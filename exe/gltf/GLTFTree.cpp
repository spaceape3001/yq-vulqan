////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFTree.hpp"
#include <tiny_gltf.h>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/im/KVTable.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/text/match.hpp>
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
    
    std::string gltf_texFilter(int n)
    {
        switch(n){
        case TINYGLTF_TEXTURE_FILTER_NEAREST:
            return "nearest";
        case TINYGLTF_TEXTURE_FILTER_LINEAR:
            return "linear";
        case TINYGLTF_TEXTURE_FILTER_NEAREST_MIPMAP_NEAREST:
            return "nearest mipmap nearest";
        case TINYGLTF_TEXTURE_FILTER_LINEAR_MIPMAP_NEAREST:
            return "linear mipmap nearest";
        case TINYGLTF_TEXTURE_FILTER_NEAREST_MIPMAP_LINEAR:
            return "nearest mipmap linear";
        case TINYGLTF_TEXTURE_FILTER_LINEAR_MIPMAP_LINEAR:
            return "linear mipmap linear";
        default:
            return std::format("Unknown filter {}", n);
        }
    }
    
    std::string gltf_texWrap(int n)
    {
        switch(n){
        case TINYGLTF_TEXTURE_WRAP_REPEAT:
            return "repeat";
        case TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE:
            return "clamp to edge";
        case TINYGLTF_TEXTURE_WRAP_MIRRORED_REPEAT:
            return "mirrored repeat";
        default:
            return std::format("Unknown wrap {}", n);
        }
    }
    
    std::string gltf_target(int n)
    {
        switch(n){
        case TINYGLTF_TARGET_ARRAY_BUFFER:
            return "array buffer";
        case TINYGLTF_TARGET_ELEMENT_ARRAY_BUFFER:
            return "element array buffer";
        default:
            return std::format("Unknown target {}", n);
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


void                    GLTFTree::model(set_k, tinygltf::ModelSPtr v, const std::filesystem::path& fp)
{
    m_model = v;
    m_filepath = fp;
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
    im::KVTable  kv("Accessor");
    kv("Name") << a.name;
    kv("Buffer View") << a.bufferView;
    kv("Byte Offset") << a.byteOffset;
    kv("Components") << gltf_componentType(a.componentType);
    kv("Count") << a.count;
    kv("Normalized") << a.normalized;
    kv("Sparse") << a.sparse.isSparse;
    kv("Type") << gltf_type(a.type);
}

void GLTFTree::r_entry(tinygltf::AnimationChannel&a)
{
    im::KVTable kv("Animation Channel");
    kv("Sampler") << a.sampler;
    kv("Target Node") << a.target_node;
}

void GLTFTree::r_entry(tinygltf::AnimationSampler&a)
{
    im::KVTable kv("Animation Sampler");
    kv("Input") << a.input;
    kv("Interpolation") << a.interpolation;
    kv("Output") << a.output;
}

void GLTFTree::r_entry(tinygltf::Animation&a)
{
    using namespace ImGui;

    im::KVTable kv("Animation");
    kv("Name") << a.name;
    kv.finish();
    
    std::string text;
    text = std::format("Channels ({})", a.channels.size());
    if(TreeNode(text.c_str())){
        if(BeginTable("Channels", 3)){
            
            TableHeadersRow();
            TableNextColumn();
            TextUnformatted("N");
            TableNextColumn();
            TextUnformatted("Sampler");
            TableNextColumn();
            TextUnformatted("Target Node");
            
            size_t  cnt = 0;
            for(auto& c : a.channels){
                TableNextRow();
                if(TableNextColumn())
                    Text(cnt++);
                if(TableNextColumn())
                    Text(c.sampler);
                if(TableNextColumn())
                    Text(c.target_node);
            }
            EndTable();
        }
        TreePop();
    }
    
    text = std::format("Samplers ({})", a.samplers.size());
    if(TreeNode(text.c_str())){
        if(BeginTable("Samplers", 4)){
            TableHeadersRow();
            TableNextColumn();
            TextUnformatted("N");
            TableNextColumn();
            TextUnformatted("Input");
            TableNextColumn();
            TextUnformatted("Output");
            TableNextColumn();
            TextUnformatted("Interpolation");

            size_t cnt = 0;
            for(auto& s: a.samplers){
                TableNextRow();
                if(TableNextColumn())
                    Text(cnt++);
                if(TableNextColumn())
                    Text(s.input);
                if(TableNextColumn())
                    Text(s.output);
                if(TableNextColumn())
                    TextUnformatted(s.interpolation);
            }

            EndTable();
        }
    }
    
}

void GLTFTree::r_entry(tinygltf::AudioEmitter&a)
{
    im::KVTable kv("Audio Emitter");
    kv("Name") << a.name;
    kv("Type") << a.type;
    kv("Distance Model") << a.distanceModel;
    kv("Gain") << a.gain;
    kv("Loop") << a.loop;
    kv("Playing") << a.playing;
    kv("Source") << a.source;
}

void GLTFTree::r_entry(tinygltf::AudioSource&a)
{
    im::KVTable kv("Audio Source");
    kv("Name") << a.name;
    kv("Buffer View") << a.bufferView;
    kv("Mime Type") << a.mimeType;
    kv("URI") << a.uri;
}

void GLTFTree::r_entry(tinygltf::Buffer&b)
{
    im::KVTable kv("Buffer");
    kv("Name") << b.name;
    kv("Data Size") << b.data.size();
    kv("URI") << b.uri;
}

void GLTFTree::r_entry(tinygltf::BufferView&b)
{
    im::KVTable kv("Buffer View");
    kv("Name") << b.name;
    kv("Buffer") << b.buffer;
    kv("Byte Offset") << b.byteOffset;
    kv("Byte Length") << b.byteLength;
    kv("Byte Stride") << b.byteStride;
    kv("Target") << gltf_target(b.target);
}

void GLTFTree::r_entry(tinygltf::Camera&c)
{
    bool    is_orthographic = is_similar(c.type, "orthographic");
    bool    is_perspective = is_similar(c.type, "persective");

    im::KVTable kv("Camera");
    kv("Name") << c.name;
    kv("Type") << c.type;

    if(is_perspective)
        kv("Aspect Ratio") << c.perspective.aspectRatio;

    if(is_orthographic)
        kv("X Magnification") << c.orthographic.xmag;

    if(is_perspective)
        kv("Y FOV") << c.perspective.yfov;

    if(is_orthographic)
        kv("Y Magnification") << c.orthographic.ymag;

    if(is_perspective)
        kv("Z Far") << c.perspective.zfar;

    if(is_orthographic)
        kv("Z Far") << c.orthographic.zfar;

    if(is_perspective)
        kv("Z Near") << c.perspective.znear;

    if(is_orthographic)
        kv("Z Far") << c.perspective.zfar;
}

void GLTFTree::r_entry(tinygltf::Image&i)
{
    im::KVTable kv("Image");
    kv("Name") << i.name;
    kv("Bits Per Channel") << i.bits;
    kv("Buffer View") << i.bufferView;
    kv("Components") << i.component;
    kv("Image Byte Count") << i.image.size();
    kv("Mime Type") << i.mimeType;
    kv("Pixel Type") << gltf_componentType(i.pixel_type);
    kv("Size") << i.width << " x " << i.height;
    kv("URI") << i.uri;
}

void GLTFTree::r_entry(tinygltf::Light&l)
{
    im::KVTable  kv("Light");
    kv("Name") << l.name;
    kv("Type") << l.type;
    kv("Color") << join(l.color, ",");
    kv("Intensity") << l.intensity;
    kv("Range") << l.range;
        
    //  ignoring spotlight....
}

void GLTFTree::r_entry(tinygltf::Material&m)
{
    im::KVTable kv("Material");
    kv("Name") << m.name;
    kv("Alpha Cutoff") << m.alphaCutoff;
    kv("Alpha Mode") << m.alphaMode;
    kv("Double Sided") << m.doubleSided;
    kv("Emissive Factor") << join(m.emissiveFactor, ",");
    kv("LODs") << join(m.lods, ",");
}

void GLTFTree::r_entry(tinygltf::Mesh&m)
{
    using namespace ImGui;
    
    im::KVTable kv("Mesh");
    kv("Name") << m.name;
    kv("Weights") << join(m.weights, ",");
    kv.finish();

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
    im::KVTable kv("Model");
    kv("File") << m_filepath;
    kv("Copyright") << m.asset.copyright;
    kv("Generator") << m.asset.generator;
    kv("Min Version") << m.asset.minVersion;
    kv("Version") << m.asset.version;
}

void GLTFTree::r_entry(tinygltf::Node&n)
{
    im::KVTable kv("Node");
    kv("Name") << n.name;
    kv("Camera") << n.camera;
    kv("Children") << join(n.children, ",");
    kv("Emitter") << n.emitter;
    kv("Light") << n.light;
    kv("LODs") << join(n.lods, ",");
    kv("Matrix") << join(n.matrix, "," );
    kv("Mesh") << n.mesh;
    kv("Rotation") << join(n.rotation, ",");
    kv("Scale") << join(n.scale, ",");
    kv("Skin") << n.skin;
    kv("Translation") << join(n.translation, ",");
    kv("Weights") << join(n.weights, ",");
}

void GLTFTree::r_entry(tinygltf::Primitive& p)
{
    using namespace ImGui;
    
    im::KVTable kv("Primitive");
    kv("Indices (Accessor)") << p.indices;
    kv("Material") << p.material;
    kv("Mode") << gltf_mode(p.mode);
    kv.finish();
    
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
    im::KVTable kv("Sampler");
    kv("Name") << s.name;
    kv("Mag Filter") << gltf_texFilter(s.magFilter);
    kv("Min Filter") << gltf_texFilter(s.minFilter);
    kv("Wrap S") << gltf_texWrap(s.wrapS);
    kv("Wrap T") << gltf_texWrap(s.wrapT);
}

void GLTFTree::r_entry(tinygltf::Scene&s)
{
    im::KVTable kv("Scene");
    kv("Name") << s.name;
    kv("Audio (Emitters)") << join(s.audioEmitters, ",");
    kv("Nodes") << join(s.nodes, ",");
}

void GLTFTree::r_entry(tinygltf::Skin&s)
{
    im::KVTable kv("Skin");
    kv("Name") << s.name;
    kv("Inverse Bind Matrices") << s.inverseBindMatrices;
    kv("Joints") << join(s.joints, ",");
    kv("Skeleton Node") << s.skeleton;
}

void GLTFTree::r_entry(tinygltf::Texture&t)
{
    im::KVTable kv("Texture");
    kv("Name") << t.name;
    kv("Sampler") << t.sampler;
    kv("Source (Image)") << t.source;
}

void    GLTFTree::render()  
{
    using namespace ImGui;
    if(!m_model){
        TextUnformatted("No Model Loaded");
        return ;
    }
    
    r_entry(*m_model);
    
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
