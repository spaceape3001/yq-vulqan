////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Obj.hpp"
#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>
//#include <yq/tachyon/typedef/gltf.hpp>
#include <filesystem>

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
    
    ObjReaderSPtr    model();
    ObjReaderSPtr    model() const;
    void             model(set_k, ObjReaderSPtr, const std::filesystem::path& fp = {});
    
    void    r_entry(const tinyobj::attrib_t&);
    void    r_entry(const tinyobj::lines_t&);
    void    r_entry(const tinyobj::material_t&);
    void    r_entry(const tinyobj::mesh_t&);
    
    void    r_entry(const tinyobj::shape_t&);
    void    r_entry(const tinyobj::tag_t&);
    
private:
    ObjReaderSPtr           m_model;
    std::filesystem::path   m_filepath;
};

