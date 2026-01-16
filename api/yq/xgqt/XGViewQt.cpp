////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/gluon/core/Logging.hpp>
#include "XGViewQt.hpp"
#include "XGNewMimeQt.hpp"
#include "XGSceneQt.hpp"
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>

namespace yq::tachyon {
    XGViewQt::XGViewQt(XGSceneQt*sc) : gluon::GraphicsView(sc), m_scene(sc)
    {
        setScene(sc);
        setAcceptDrops(true);
    }
    
    XGViewQt::~XGViewQt()
    {
    }

    void    XGViewQt::dragEnterEvent(QDragEnterEvent*evt)
    {
        if(dynamic_cast<const XGNewMimeQt*>(evt->mimeData())){
            evt -> accept();
        } else {
            evt -> ignore();
        }
    }

    void    XGViewQt::dragLeaveEvent(QDragLeaveEvent*evt) 
    {
    }
    
    void    XGViewQt::dragMoveEvent(QDragMoveEvent*evt) 
    {
    
    }
    
    void    XGViewQt::dropEvent(QDropEvent* evt) 
    {
        if(const XGNewMimeQt* nm = dynamic_cast<const XGNewMimeQt*>(evt->mimeData())){
            m_scene -> add(nm->node_spec(), mapToScene(evt->position().toPoint()));
        }
    }
}

#include "moc_XGViewQt.cpp"
