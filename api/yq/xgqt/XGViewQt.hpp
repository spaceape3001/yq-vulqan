////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/graphics/GraphicsView.hpp>

namespace yq::tachyon {
    class XGSceneQt;
    class XGViewQt : public gluon::GraphicsView {
        Q_OBJECT
    public:
        XGViewQt(XGSceneQt*);
        ~XGViewQt();
        
    protected:
        void    dragEnterEvent(QDragEnterEvent*) override;
        void    dragLeaveEvent(QDragLeaveEvent*) override;
        void    dragMoveEvent(QDragMoveEvent*) override;
        void    dropEvent(QDropEvent*) override;
    private:
        XGSceneQt*          m_scene     = nullptr;
        QGraphicsItem*      m_dragItem  = nullptr;
    };
}
