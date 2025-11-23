////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>

using namespace yq;
using namespace yq::tachyon;

class GLTFTree : public UIElement {
    YQ_OBJECT_DECLARE(GLTFTree, UIElement)
public:
    GLTFTree(UIFlags flags={});
    GLTFTree(const GLTFTree&);
    ~GLTFTree();
    GLTFTree* clone() const override;
    void    render()  override;
    static void init_meta();
};

class TreePanel : public UIWindow {
    YQ_OBJECT_DECLARE(TreePanel, UIElement)
public:
    TreePanel(UIFlags flags={});
    TreePanel(const TreePanel&);
    ~TreePanel();
    TreePanel* clone() const override;
    void    render()  override;
    static void init_meta();
};
