////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/physics.hpp>

namespace yq::tachyon{
    class Frame;

    class PhysicsTableUI : public UIElement {
        YQ_OBJECT_DECLARE(PhysicsTableUI, UIElement)
    public:
        static void init_meta();
        
        PhysicsTableUI(UIFlags flags={});
        PhysicsTableUI(const PhysicsTableUI& cp);
        
        virtual PhysicsTableUI*   clone() const;
        const char*    title() const override;
        
        void    render() override;

        PhysicsID         selected() const { return m_selected; }
        void            set_selected(PhysicsID);

        void            tick() override;

    private:

        struct Row;
        
        
        void            changed_select();

        TextureID           m_editing;
        PhysicsID             m_selected;
        std::vector<Row>    m_rows;
    };

}
