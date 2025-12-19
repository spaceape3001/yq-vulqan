////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/camera.hpp>

namespace yq::tachyon{
    class Frame;
};

using namespace yq;
using namespace yq::tachyon;

class SceneTableUI : public UIElement {
    YQ_OBJECT_DECLARE(SceneTableUI, UIElement)
public:
    static void init_meta();
    
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
        const SceneMeta*    info = nullptr;
        bool                visible = false;
    };
    
    std::vector<Snap>       snaps() const;

    void            tick() override;

private:

    struct Row;
    
    Row*            row(SceneID);
    const Row*      row(SceneID) const;
    
    
    void            changed_select();

    TextureID           m_editing;
    TextureID           m_invisible;
    TextureID           m_visible;
    SceneID             m_selected;
    std::vector<Row>    m_rows;
};

