////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGSceneQt.hpp"
#include <yq/xg/XGDocument.hpp>

namespace yq::tachyon {

    XGSceneQt::XGSceneQt(QObject*parent) : XGSceneQt({}, parent)
    {
    }
    
    XGSceneQt::XGSceneQt(XGDocumentPtr doc, QObject*parent) : gluon::GraphicsScene(parent)
    {
        if(doc){
            m_doc   = doc;
        } else
            m_doc   = new XGDocument;
    }
    
    XGSceneQt::~XGSceneQt()
    {
    }
}

#include "moc_XGSceneQt.cpp"

