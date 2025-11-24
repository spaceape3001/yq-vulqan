////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/tachyon/typedef/gltf.hpp>

using namespace yq;
using namespace yq::tachyon;

//  Use this... 
using gltfModelSPtr = std::shared_ptr<tinygltf::Model>;

class GLTFTree : public UIElement {
    YQ_OBJECT_DECLARE(GLTFTree, UIElement)
public:
    GLTFTree(UIFlags flags={});
    GLTFTree(const GLTFTree&);
    ~GLTFTree();
    GLTFTree* clone() const override;
    void    render()  override;
    static void init_meta();
    
    tinygltf::ModelSPtr     model();
    tinygltf::ModelSCPtr    model() const;
    void                    model(set_k, tinygltf::ModelSPtr, const std::filesystem::path& fp = {});
    
private:
    tinygltf::ModelSPtr     m_model;
    std::filesystem::path   m_filepath;
    
    void r_entry(tinygltf::Accessor&);
    void r_entry(tinygltf::Animation&);
    void r_entry(tinygltf::AnimationChannel&);
    void r_entry(tinygltf::AnimationSampler&);
    void r_entry(tinygltf::AudioSource&);
    void r_entry(tinygltf::AudioEmitter&);
    void r_entry(tinygltf::Buffer&);
    void r_entry(tinygltf::BufferView&);
    void r_entry(tinygltf::Camera&);
    void r_entry(tinygltf::Image&);
    void r_entry(tinygltf::Light&);
    void r_entry(tinygltf::Material&);
    void r_entry(tinygltf::Mesh&);
    void r_entry(tinygltf::Model&);
    void r_entry(tinygltf::Node&);
    void r_entry(tinygltf::Primitive&);
    void r_entry(tinygltf::Sampler&);
    void r_entry(tinygltf::Scene&);
    void r_entry(tinygltf::Skin&);
    void r_entry(tinygltf::Texture&);
};
