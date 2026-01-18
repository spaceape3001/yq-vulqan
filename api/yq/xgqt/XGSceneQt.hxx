////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gluon/graphics/GraphicsSymbolItem.hpp>
#include <yq/xg/XGDocEdge.hpp>
#include <yq/xg/XGDocLine.hpp>
#include <yq/xg/XGDocNode.hpp>
#include <yq/xg/XGDocText.hpp>
#include <yq/xgqt/XGSceneQt.hpp>

#include <QGraphicsItemGroup>
#include <QGraphicsPathItem>

class QGraphicsRectItem;
class QGraphicsTextItem;

namespace yq {
    struct XGDocNode;
    struct XGNodeMeta;
}

namespace yq::tachyon {
    struct XGSceneQt::Item {
        Item();
        virtual ~Item();
        
        virtual QGraphicsItem*          qItem() = 0;
        virtual const QGraphicsItem*    qItem() const = 0;
    };
    
    struct XGSceneQt::Node : public gluon::GraphicsSymbolItem, public Item  {
        XGDocNode               m_data;
        QGraphicsRectItem*      m_box   = nullptr;
        QGraphicsTextItem*      m_text  = nullptr;
        
        //  Node(const Node&);  // pending/TODO
        Node(const XGDocNode&);
        Node(const XGNodeMeta&, const QPointF&);
        
        using gluon::GraphicsSymbolItem::build;
        
        void    build(std::string_view sym={});
        virtual ~Node();

        virtual QGraphicsItem*          qItem() override { return this; }
        virtual const QGraphicsItem*    qItem() const override { return this; }
    };
    
    struct XGSceneQt::Text : public QGraphicsItemGroup, public Item {
        XGDocText               m_data;
        QGraphicsRectItem*      m_box   = nullptr;
        QGraphicsTextItem*      m_text  = nullptr;

        virtual QGraphicsItem*          qItem() override { return this; }
        virtual const QGraphicsItem*    qItem() const override { return this; }
    };
    
    struct XGSceneQt::Line : public QGraphicsPathItem, public Item {
        XGDocLine               m_data;

        virtual QGraphicsItem*          qItem() override { return this; }
        virtual const QGraphicsItem*    qItem() const override { return this; }
    };
    
    struct XGSceneQt::Edge : public QGraphicsPathItem, public Item {
        Node*                   m_source   = nullptr;
        Node*                   m_target   = nullptr;
        XGDocEdge               m_data;

        virtual QGraphicsItem*          qItem() override { return this; }
        virtual const QGraphicsItem*    qItem() const override { return this; }
    };
}
