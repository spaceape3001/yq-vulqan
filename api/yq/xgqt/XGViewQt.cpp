////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGViewQt.hpp"
#include "XGSceneQt.hpp"

namespace yq::tachyon {
    XGViewQt::XGViewQt(XGSceneQt*sc) : gluon::GraphicsView(sc), m_scene(sc)
    {
        setScene(sc);
    }
    
    XGViewQt::~XGViewQt()
    {
    }
}

#include "moc_XGViewQt.cpp"
