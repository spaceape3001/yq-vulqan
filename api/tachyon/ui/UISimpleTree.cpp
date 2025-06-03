////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UISimpleTree.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UISimpleTree)

namespace yq::tachyon {
    void UISimpleTree::init_info()
    {
        auto w = writer<UISimpleTree>();
        w.description("Simple tree of elements");
    }
    
    UISimpleTree::UISimpleTree(UIFlags flags) : UIElements(flags)
    {
    }
    
    UISimpleTree::UISimpleTree(const UISimpleTree& cp) : UIElements(cp)
    {
    }
    
    UISimpleTree* UISimpleTree::clone() const 
    {
        return new UISimpleTree(*this);
    }
    
    void UISimpleTree::render() 
    {
        unsigned int n  = 0;
        for(UIElement* e : m_items){
            std::string_view    itemTitle;
            if(const char* p = e->title())
                itemTitle   = p;
            std::string     id  = std::format("{}##TREENODE{}", itemTitle, ++n);
            if(ImGui::TreeNode(id.c_str())){
                e->draw();
                ImGui::TreePop();
            }
        }
    }
}
