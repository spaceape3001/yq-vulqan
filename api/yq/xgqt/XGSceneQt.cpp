////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGSceneQt.hpp"
#include "XGSceneQt.hxx"
#include <yq/xg/XGDocument.hpp>
#include <yq/xg/XGDocNode.hpp>
#include <yq/xg/XGNodeMeta.hpp>
#include <yq/gluon/core/Utilities.hpp>

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

using namespace yq::gluon;

namespace yq::tachyon {

    XGSceneQt::XGSceneQt(QObject*parent) : GraphicsScene(parent)
    {
    }

    XGSceneQt::~XGSceneQt()
    {
    }

    void    XGSceneQt::add(const XGNodeMeta&nn, const QPointF&pt)
    {
        Node*n  = new Node(nn, pt);
        addItem(n);
    }
    
    //void    XGSceneQt::add(const XGDocNode&dn)
    //{
    //}
    

    bool            XGSceneQt::set(const XGDocument&doc)
    {
        return true;
    }
    
    XGDocumentPtr   XGSceneQt::get() const
    {
        return new XGDocument;
    }
    
    //////////////////////////////////////////////////////////////////////////////

    XGSceneQt::Item::Item() = default;
    XGSceneQt::Item::~Item() = default;

    //////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////
    XGSceneQt::Node::Node(const XGDocNode& xn) : m_data(xn)
    {
        build();
    }
    
    XGSceneQt::Node::Node(const XGNodeMeta& xn, const QPointF& pt)
    {
        m_data.bgcolor      = xn.bgcolor;
        m_data.color        = xn.color;
        m_data.position     = { (float) pt.x(), (float) pt.y() };
        m_data.size         = { 100.f, 50.f };  // hack
        m_data.node_type    = xn.node_type;
        m_data.spec_type    = xn.spec_type;
        m_data.spec_data    = xn.spec_data;
        m_data.label        = xn.label;
        
        build();
    }
    

    XGSceneQt::Node::~Node()
    {
    }

    void    XGSceneQt::Node::build()
    {
        m_box   = new QGraphicsRectItem(-0.5*m_data.size.x, -0.5*m_data.size.y, m_data.size.x, m_data.size.y, this);
        m_text  = new QGraphicsTextItem(qString(m_data.label), this);

        addToGroup(m_box);
        addToGroup(m_text);
        setPos({m_data.position.x, m_data.position.y});
    }

    //////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////

}

#include "moc_XGSceneQt.cpp"

