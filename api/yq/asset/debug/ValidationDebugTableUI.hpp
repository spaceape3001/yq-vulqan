////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/vi_debug_trace.hpp>

namespace yq::tachyon {
    class ValidationDebugTableUI : public UIElement {
        YQ_OBJECT_DECLARE(ValidationDebugTableUI, UIElement)
    public:
        
        ValidationDebugTableUI(UIFlags flags={});
        ValidationDebugTableUI(const ValidationDebugTableUI&);
        ~ValidationDebugTableUI();
        ValidationDebugTableUI* clone() const;
        
        static void init_meta();
        void render() override;
        
        void render(const ViDebugTrace&);
        
        void add(const ViDebugTraceCPtr&);
        
    private:
        std::vector<ViDebugTraceCPtr>   m_data;
    };
}
