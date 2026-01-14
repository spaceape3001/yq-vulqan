////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGSceneQt.hpp"
#include <yq/xg/XGDocument.hpp>

namespace yq::tachyon {

    XGSceneQt::XGSceneQt(QObject*parent) : gluon::GraphicsScene(parent)
    {
    }

    XGSceneQt::~XGSceneQt()
    {
    }

    bool            XGSceneQt::set(const XGDocument&doc)
    {
        return true;
    }
    
    XGDocumentPtr   XGSceneQt::get() const
    {
        return new XGDocument;
    }
}

#include "moc_XGSceneQt.cpp"

