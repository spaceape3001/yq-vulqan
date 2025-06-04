////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneEditor.hpp"
#include <tachyon/ui/UIMenu.hpp>

class SceneEditor::CameraAddMenuUI : public UIMenu {
    YQ_OBJECT_DECLARE(CameraAddMenuUI, UIMenu)
public:

    static void init_info();

    CameraAddMenuUI(std::string_view, UIFlags flags={});
    CameraAddMenuUI(const CameraAddMenuUI&);
    virtual ~CameraAddMenuUI();
    
    virtual CameraAddMenuUI* clone() const override;
    
    void content() override;

private:
    struct Item;
    std::vector<Item>  m_items;
    
    void    build_menu();
};
