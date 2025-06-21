////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/ui/UIMenu.hpp>

class SceneEditor::LightAddMenuUI : public UIMenu {
    YQ_OBJECT_DECLARE(LightAddMenuUI, UIMenu)
public:

    static void init_info();

    LightAddMenuUI(std::string_view, UIFlags flags={});
    LightAddMenuUI(const LightAddMenuUI&);
    virtual ~LightAddMenuUI();
    
    virtual LightAddMenuUI* clone() const override;
    
    void content() override;

private:
    struct Item;
    std::vector<Item>  m_items;
    
    void    build_menu();
};
