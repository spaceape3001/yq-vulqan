////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>
#include <tachyon/typedef/scene.hpp>
#include <tachyon/typedef/camera.hpp>

namespace yq::tachyon{
    class Frame;
};

using namespace yq;
using namespace yq::tachyon;

class SceneTableUI : public UIElement {
    YQ_OBJECT_DECLARE(SceneTableUI, UIElement)
public:
    static void init_info();
    
    SceneTableUI(UIFlags flags={});
    SceneTableUI(const SceneTableUI& cp);
    
    virtual SceneTableUI*   clone() const;
    const char*    title() const override;
    
    void    render() override;

    SceneID         selected() const { return m_selected; }
    void            set_selected(SceneID);

    bool            visible(SceneID) const;
    CameraID        camera(SceneID) const;
    
    std::vector<SceneID>    scenes() const;

    struct Snap {
        SceneID             scene;
        CameraID            camera;
        const SceneInfo*    info = nullptr;
        bool                visible = false;
    };
    
    std::vector<Snap>       snaps() const;

    void            tick() override;

private:

    struct Row;
    
    Row*            row(SceneID);
    const Row*      row(SceneID) const;
    
    
    void            changed_select();

    ImTextureID         m_editing = nullptr;
    ImTextureID         m_invisible    = nullptr;
    ImTextureID         m_visible      = nullptr;
    SceneID             m_selected;
    std::vector<Row>    m_rows;
};

