////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xgvk/ui/XGViewUI.hpp>
#include <yq/assetvk/ui/UICanvasWriter.hpp>

namespace yq::tachyon {
    class XGViewUI;

    class XGViewUIWriter : public UICanvasWriter {
    public:
    public:
        XGViewUIWriter();
        XGViewUIWriter(XGViewUI*);
        XGViewUIWriter(const XGViewUIWriter&);
        ~XGViewUIWriter();
        
        XGViewUI*  element();
    };
}
