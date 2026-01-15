////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <QMimeData>
#include <yq/xg/XGNodeMeta.hpp>

namespace yq::tachyon {
    class XGNewMimeQt : public QMimeData {
        Q_OBJECT
    public:
    
        XGNewMimeQt(const XGNodeMeta&);
        ~XGNewMimeQt();
        
        const XGNodeMeta&    node_spec() const { return m_node; }
        
    private:
        const XGNodeMeta   m_node;
    };
}
