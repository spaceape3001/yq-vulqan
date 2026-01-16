////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/widget/PaletteWidget.hpp>

namespace yq {
    struct XGNodeMeta;
    struct XGManifest;
}

namespace yq::tachyon {
    class XGPaletteQt : public gluon::PaletteWidget {
        Q_OBJECT
    public:
        XGPaletteQt(QWidget*parent=nullptr);
        XGPaletteQt(const XGManifest&, QWidget*parent=nullptr);
        ~XGPaletteQt();
        
        struct Item;
        
    protected:
        virtual QMimeData*  mimeData(const gluon::PaletteWidget::Item*) const;
    private:
        XGPaletteQt(const XGManifest*, QWidget*parent);
        void _populate(std::vector<XGNodeMeta>&);
    };
}

