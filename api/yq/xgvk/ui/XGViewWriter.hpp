////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UICanvasWriter.hpp>

namespace yq::xg {
    class XGView;

    class XGViewWriter : public tachyon::UICanvasWriter {
    public:
    public:
        XGViewWriter();
        XGViewWriter(XGView*);
        XGViewWriter(const XGViewWriter&);
        ~XGViewWriter();
        
        XGView*  element();
    };
}
