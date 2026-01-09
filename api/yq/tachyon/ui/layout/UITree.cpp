////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UITree.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UITree)

namespace yq::tachyon {
    void UITree::init_meta()
    {
        auto w = writer<UITree>();
        w.description("Simple tree of elements");
    }
    
    UITree::UITree(UIFlags flags) : UIElements(flags)
    {
    }
    
    UITree::UITree(const UITree& cp) : UIElements(cp)
    {
    }
    
    UITree* UITree::clone() const 
    {
        return new UITree(*this);
    }
    
    void UITree::render() 
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
