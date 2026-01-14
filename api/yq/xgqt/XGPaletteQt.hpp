////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/widget/PaletteWidget.hpp>

namespace yq::tachyon {
    class XGPaletteQt : public gluon::PaletteWidget {
        Q_OBJECT
    public:
        XGPaletteQt(QWidget*parent=nullptr);
        ~XGPaletteQt();
        
    private:
        void _populate();
    };
}

