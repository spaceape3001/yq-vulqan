////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/typedef/xg_document.hpp>
#include <yq/core/Ref.hpp>
#include <yq/gluon/graphics/GraphicsCanvas.hpp>
#include <filesystem>

namespace yq::tachyon {
    class XGSceneQt;
    class XGViewQt;

    class XGCanvasQt : public gluon::GraphicsCanvas {
        Q_OBJECT
    public:
    
        XGCanvasQt(QWidget*parent=nullptr);
        XGCanvasQt(XGDocumentPtr,QWidget*parent=nullptr);
        ~XGCanvasQt();
        
        XGDocument&         document() { return *m_doc; }
        const XGDocument&   document() const { return *m_doc; }
        
        XGSceneQt*          scene() { return m_scene; }
        const XGSceneQt*    scene() const { return m_scene; }
        
        XGViewQt*           view() { return m_view; }
        const XGViewQt*     view() const { return m_view; }
        
        std::filesystem::path   dirpath() const;
        QString                 dirname() const;
        
        std::filesystem::path   filepath() const;
        QString                 filename() const;

    public slots:
        void        updateTitle();
        
    private:
        const unsigned      m_number;
        XGDocumentPtr       m_doc;
        XGSceneQt*          m_scene     = nullptr;
        XGViewQt*           m_view      = nullptr;
    };
}
