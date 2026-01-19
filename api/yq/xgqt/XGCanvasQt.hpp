////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/typedef/xg_document.hpp>
#include <yq/core/Ref.hpp>
#include <yq/gluon/graphics/GraphicsCanvas.hpp>
#include <yq/net/Url.hpp>
#include <filesystem>

namespace yq::gluon {
    class GraphScene;
    class GraphView;
}

namespace yq::tachyon {
    class XGSceneQt;
    class XGViewQt;

    class XGCanvasQt : public gluon::GraphicsCanvas {
        Q_OBJECT
    public:
    
        XGCanvasQt(QWidget*parent=nullptr);
        ~XGCanvasQt();
        
        gluon::GraphScene*          scene() { return m_scene; }
        const gluon::GraphScene*    scene() const { return m_scene; }
        
        gluon::GraphView*           view() { return m_view; }
        const gluon::GraphView*     view() const { return m_view; }
        
        std::filesystem::path       dirpath() const;
        QString                     dirname() const;
        
        std::filesystem::path       filepath() const;
        QString                     filename() const;
        
        XGDocumentPtr               get() const;
        void                        set(const XGDocument&);
        
        const Url& url() const { return m_url; }
        

    public slots:
        void        updateTitle();
        void        clear();
        
    private:
        const unsigned          m_number;
        Url                     m_url;
        gluon::GraphScene*      m_scene     = nullptr;
        gluon::GraphView*       m_view      = nullptr;
    };
}
