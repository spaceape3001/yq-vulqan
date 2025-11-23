////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFTree.hpp"
#include <tiny_gltf.h>
#include <yq/tachyon/MyImGui.hpp>
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

void GLTFTree::r_entry(tinygltf::AnimationChannel&a)
{
    using namespace ImGui;

    if(BeginTable("AnimationChannel", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Sampler");
        if(TableNextColumn())
            Text(a.sampler);
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Target Node");
        if(TableNextColumn())
            Text(a.target_node);

        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::AnimationSampler&a)
{
    using namespace ImGui;

    if(BeginTable("AnimationSampler", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Input");
        if(TableNextColumn())
            Text(a.input);
        
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Interpolation");
        if(TableNextColumn())
            TextUnformatted(a.interpolation);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Output");
        if(TableNextColumn())
            Text(a.output);
        
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
    using namespace ImGui;

    if(BeginTable("AudioEmitter", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(a.name);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Type");
        if(TableNextColumn())
            TextUnformatted(a.type);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Distance Model");
        if(TableNextColumn())
            TextUnformatted(a.distanceModel);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Gain");
        if(TableNextColumn())
            Text(a.gain);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Loop");
        if(TableNextColumn())
            Text(a.loop);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Playing");
        if(TableNextColumn())
            Text(a.playing);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Source");
        if(TableNextColumn())
            Text(a.source);

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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Buffer View");
        if(TableNextColumn())
            Text(a.bufferView);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Mime Type");
        if(TableNextColumn())
            TextUnformatted(a.mimeType);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("URI");
        if(TableNextColumn())
            TextUnformatted(a.uri);


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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Data Size");
        if(TableNextColumn())
            Text(b.data.size());

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("URI");
        if(TableNextColumn())
            TextUnformatted(b.uri);

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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Buffer");
        if(TableNextColumn())
            Text(b.buffer);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Byte Offset");
        if(TableNextColumn())
            Text(b.byteOffset);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Byte Length");
        if(TableNextColumn())
            Text(b.byteLength);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Byte Stride");
        if(TableNextColumn())
            Text(b.byteStride);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Target");
        if(TableNextColumn())
            TextUnformatted(gltf_target(b.target));


        EndTable();
    }
}

void GLTFTree::r_entry(tinygltf::Camera&c)
{
    using namespace ImGui;

    bool    is_orthographic = is_similar(c.type, "orthographic");
    bool    is_perspective = is_similar(c.type, "persective");

    if(BeginTable("Camera", 2)){
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Name");
        if(TableNextColumn())
            TextUnformatted(c.name);
    
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Type");
        if(TableNextColumn())
            TextUnformatted(c.type);

        if(is_perspective){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("Aspect Ratio");
            if(TableNextColumn())
                Text(c.perspective.aspectRatio);
        }

        if(is_orthographic){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("X Magnification");
            if(TableNextColumn())
                Text(c.orthographic.xmag);
        }

        if(is_perspective){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("Y FOV");
            if(TableNextColumn())
                Text(c.perspective.yfov);
        }

        if(is_orthographic){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("Y Magnification");
            if(TableNextColumn())
                Text(c.orthographic.ymag);
        }

        if(is_perspective){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("Z Far");
            if(TableNextColumn())
                Text(c.perspective.zfar);
        }

        if(is_orthographic){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("Z Far");
            if(TableNextColumn())
                Text(c.orthographic.zfar);
        }

        if(is_perspective){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("Z Near");
            if(TableNextColumn())
                Text(c.perspective.znear);
        }

        if(is_orthographic){
            TableNextRow();
            if(TableNextColumn())
                TextUnformatted("Z Near");
            if(TableNextColumn())
                Text(c.orthographic.znear);
        }


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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Bits Per Channel");
        if(TableNextColumn())
            Text(i.bits);


        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Buffer View");
        if(TableNextColumn())
            Text(i.bufferView);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Components");
        if(TableNextColumn())
            Text(i.component);


        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Height");
        if(TableNextColumn())
            Text(i.height);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Image Byte Count");
        if(TableNextColumn())
            Text(i.image.size());

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Mime Type");
        if(TableNextColumn())
            TextUnformatted(i.mimeType);


        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Pixel Type");
        if(TableNextColumn())
            TextUnformatted(gltf_componentType(i.pixel_type));


        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("URI");
        if(TableNextColumn())
            TextUnformatted(i.uri);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Width");
        if(TableNextColumn())
            Text(i.width);


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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Type");
        if(TableNextColumn())
            TextUnformatted(l.type);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Color");
        if(TableNextColumn())
            TextUnformatted(join(l.color, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Intensity");
        if(TableNextColumn())
            Text(l.intensity);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Range");
        if(TableNextColumn())
            Text(l.range);
            
        //  ignoring spotlight....

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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Alpha Cutoff");
        if(TableNextColumn())
            Text(m.alphaCutoff);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Alpha Mode");
        if(TableNextColumn())
            TextUnformatted(m.alphaMode);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Double Sided");
        if(TableNextColumn())
            Text(m.doubleSided);


        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Emissive Factor");
        if(TableNextColumn())
            TextUnformatted(join(m.emissiveFactor, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("LODs");
        if(TableNextColumn())
            TextUnformatted(join(m.lods, ","));

        // more TBD

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
            TextUnformatted(join(m.weights, ","));

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
            TextUnformatted(join(n.children, ","));

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
            TextUnformatted(join(n.lods, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Matrix");
        if(TableNextColumn())
            TextUnformatted(join(n.matrix, "," ));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Mesh");
        if(TableNextColumn())
            Text(n.mesh);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Rotation");
        if(TableNextColumn())
            TextUnformatted(join(n.rotation, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Scale");
        if(TableNextColumn())
            TextUnformatted(join(n.scale, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Skin");
        if(TableNextColumn())
            Text(n.skin);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Translation");
        if(TableNextColumn())
            TextUnformatted(join(n.translation, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Weights");
        if(TableNextColumn())
            TextUnformatted(join(n.weights, ","));

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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Mag Filter");
        if(TableNextColumn())
            TextUnformatted(gltf_texFilter(s.magFilter));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Min Filter");
        if(TableNextColumn())
            TextUnformatted(gltf_texFilter(s.minFilter));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Wrap S");
        if(TableNextColumn())
            TextUnformatted(gltf_texWrap(s.wrapS));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Wrap T");
        if(TableNextColumn())
            TextUnformatted(gltf_texWrap(s.wrapT));

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
            
        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Audio (Emitters)");
        if(TableNextColumn())
            TextUnformatted(join(s.audioEmitters, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Nodes");
        if(TableNextColumn())
            TextUnformatted(join(s.nodes, ","));
        

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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Inverse Bind Matrices");
        if(TableNextColumn())
            Text(s.inverseBindMatrices);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Joints");
        if(TableNextColumn())
            TextUnformatted(join(s.joints, ","));

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Skeleton Node");
        if(TableNextColumn())
            Text(s.skeleton);
        

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

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Sampler");
        if(TableNextColumn())
            Text(t.sampler);

        TableNextRow();
        if(TableNextColumn())
            TextUnformatted("Source (Image)");
        if(TableNextColumn())
            Text(t.source);

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
