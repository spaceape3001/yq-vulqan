////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/ui/UIMenu.hpp>

class SceneEditor::SceneAddMenuUI : public UIMenu {
    YQ_OBJECT_DECLARE(SceneAddMenuUI, UIMenu)
public:

    static void init_info();

    SceneAddMenuUI(std::string_view, UIFlags flags={});
    SceneAddMenuUI(const SceneAddMenuUI&);
    virtual ~SceneAddMenuUI();
    
    virtual SceneAddMenuUI* clone() const override;
    
    void content() override;

private:
    struct Item;
    std::vector<Item>  m_items;
    
    void    build_menu();
};
