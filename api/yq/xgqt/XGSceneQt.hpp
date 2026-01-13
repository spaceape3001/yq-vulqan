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
        XGSceneQt(XGDocumentPtr, QObject*parent=nullptr);
        ~XGSceneQt();
        
        auto&           document() { return m_doc; }
        const auto&     document() const { return m_doc; }
        
    private:
        XGDocumentPtr           m_doc;
    };
}
