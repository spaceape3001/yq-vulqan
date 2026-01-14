////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/graphics/GraphicsScene.hpp>
#include <yq/core/Ref.hpp>
#include <yq/typedef/xg_document.hpp>

namespace yq::tachyon {
    class XGSceneQt : public gluon::GraphicsScene {
        Q_OBJECT
    public:
        XGSceneQt(QObject*parent=nullptr);
        ~XGSceneQt();
        
        bool            set(const XGDocument&);
        XGDocumentPtr   get() const;
        
        /*
            I *was* assuming retaining the document... better to 
            push it into items and pull it back.  Load/Export sort 
            of thing.
        */
    };
}
