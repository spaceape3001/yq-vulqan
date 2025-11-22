////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/canvasvk/UICanvas.hpp>

namespace yq::tachyon {
    class XGViewWriter;
    
    class XGView : public UICanvas {
        YQ_OBJECT_DECLARE(XGView, UICanvas)
    public:
        using Writer = XGViewWriter;
    
        XGView(std::string_view k="##XGView", UIFlags flags={});
        XGView(const XGView&);
        virtual ~XGView();
        
        XGView* clone() const override;
        
        static void init_info();
    private:
    };
}
