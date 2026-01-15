////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/graphics/GraphicsScene.hpp>
#include <yq/core/Ref.hpp>
#include <yq/typedef/xg_document.hpp>

namespace yq {
    struct XGDocDoc;
    struct XGDocNode;
    struct XGDocText;
    struct XGDocLine;
    struct XGDocEdge;
    struct XGNodeMeta;
}

namespace yq::tachyon {
    class XGSceneQt : public gluon::GraphicsScene {
        Q_OBJECT
    public:
        XGSceneQt(QObject*parent=nullptr);
        ~XGSceneQt();
        
        bool            set(const XGDocument&);
        XGDocumentPtr   get() const;
        
        void            add(const XGNodeMeta&, const QPointF&);
        //void    add(const XGDocNode&);
        
        /*
            I *was* assuming retaining the document... better to 
            push it into items and pull it back.  Load/Export sort 
            of thing.
        */
        
        struct Item;
        struct Node;
        struct Edge;
        struct Line;
        struct Text;
        
    };
    
}
