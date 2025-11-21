////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UICanvas.hpp>

namespace yq::xg {
    class XGViewWriter;
    
    class XGView : public tachyon::UICanvas {
        YQ_OBJECT_DECLARE(XGView, tachyon::UICanvas)
    public:
        using Writer = XGViewWriter;
    
        XGView(std::string_view k="##XGView", tachyon::UIFlags flags={});
        XGView(const XGView&);
        virtual ~XGView();
        
        XGView* clone() const override;
        
        static void init_info();
    private:
    };
}
