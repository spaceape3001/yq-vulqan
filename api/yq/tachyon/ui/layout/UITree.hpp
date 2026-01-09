////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElements.hpp>

namespace yq::tachyon {
    class UITree : public UIElements {
        YQ_OBJECT_DECLARE(UITree, UIElements)
    public:
        static void init_meta();
        UITree(UIFlags flags={});
        UITree(const UITree&);
        virtual UITree* clone() const override;
        virtual void render() override;
    };
}
