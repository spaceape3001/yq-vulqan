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

void    ObjTree::render()  
{
    using namespace ImGui;
    TextUnformatted("Object Tree... (TODO)");
}

YQ_OBJECT_IMPLEMENT(ObjTree)
