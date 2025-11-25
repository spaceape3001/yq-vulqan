////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>
//#include <yq/tachyon/typedef/gltf.hpp>

using namespace yq;
using namespace yq::tachyon;

class ObjTree : public UIElement {
    YQ_OBJECT_DECLARE(ObjTree, UIElement)
public:
    ObjTree(UIFlags flags={});
    ObjTree(const ObjTree&);
    ~ObjTree();
    ObjTree* clone() const override;
    void    render()  override;
    static void init_meta();
    
    //tinygltf::ModelSPtr     model();
    //tinygltf::ModelSCPtr    model() const;
    //void                    model(set_k, tinygltf::ModelSPtr, const std::filesystem::path& fp = {});
    
private:
    //tinygltf::ModelSPtr     m_model;
    std::filesystem::path   m_filepath;
};

