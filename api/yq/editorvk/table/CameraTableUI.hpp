////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/camera.hpp>

namespace yq::tachyon{

    class CameraTableUI : public UIElement {
        YQ_OBJECT_DECLARE(CameraTableUI, UIElement)
    public:
        static void init_meta();
        
        CameraTableUI(UIFlags flags={});
        CameraTableUI(const CameraTableUI& cp);
        
        virtual CameraTableUI*   clone() const;
        const char*    title() const override;
        
        void    render() override;

        CameraID        selected() const { return m_selected; }
        void            set_selected(CameraID);

        void            tick() override;

    private:

        struct Row;
        
        void            changed_select();

        TextureID           m_editing;
        CameraID            m_selected;
        std::vector<Row>    m_rows;
    };

}
