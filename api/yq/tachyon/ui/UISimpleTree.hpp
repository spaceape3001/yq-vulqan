////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>

namespace yq::tachyon {
    class UISimpleTree : public UIElements {
        YQ_OBJECT_DECLARE(UISimpleTree, UIElements)
    public:
        static void init_meta();
        UISimpleTree(UIFlags flags={});
        UISimpleTree(const UISimpleTree&);
        virtual UISimpleTree* clone() const override;
        virtual void render() override;
    };
}
