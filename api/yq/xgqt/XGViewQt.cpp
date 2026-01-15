////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGViewQt.hpp"
#include "XGSceneQt.hpp"
#include <QDragEnterEvent>

namespace yq::tachyon {
    XGViewQt::XGViewQt(XGSceneQt*sc) : gluon::GraphicsView(sc), m_scene(sc)
    {
        setScene(sc);
    }
    
    XGViewQt::~XGViewQt()
    {
    }

    void    XGViewQt::dragEnterEvent(QDragEnterEvent*evt)
    {
        evt -> accept();
    }
    
}

#include "moc_XGViewQt.cpp"
