////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/ui/UICanvas.hpp>

namespace yq::tachyon {
    class XGViewUIWriter;
    
    class XGViewUI : public UICanvas {
        YQ_OBJECT_DECLARE(XGViewUI, UICanvas)
    public:
        using Writer = XGViewUIWriter;
    
        XGViewUI(std::string_view k="##XGViewUI", UIFlags flags={});
        XGViewUI(const XGViewUI&);
        virtual ~XGViewUI();
        
        XGViewUI* clone() const override;
        
        static void init_info();
    private:
    };
}
