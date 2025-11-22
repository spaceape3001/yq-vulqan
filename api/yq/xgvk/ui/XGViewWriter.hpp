////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/canvasvk/UICanvasWriter.hpp>

namespace yq::tachyon {
    class XGView;

    class XGViewWriter : public UICanvasWriter {
    public:
    public:
        XGViewWriter();
        XGViewWriter(XGView*);
        XGViewWriter(const XGViewWriter&);
        ~XGViewWriter();
        
        XGView*  element();
    };
}
