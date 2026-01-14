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

namespace yq::tachyon {
    class XGSceneQt;
    class XGViewQt;

    class XGCanvasQt : public gluon::GraphicsCanvas {
        Q_OBJECT
    public:
    
        XGCanvasQt(QWidget*parent=nullptr);
        ~XGCanvasQt();
        
        XGSceneQt*              scene() { return m_scene; }
        const XGSceneQt*        scene() const { return m_scene; }
        
        XGViewQt*               view() { return m_view; }
        const XGViewQt*         view() const { return m_view; }
        
        std::filesystem::path   dirpath() const;
        QString                 dirname() const;
        
        std::filesystem::path   filepath() const;
        QString                 filename() const;
        
        XGDocumentPtr           get() const;
        void                    set(const XGDocument&);
        
        const Url& url() const { return m_url; }
        

    public slots:
        void        updateTitle();
        void        clear();
        
    private:
        const unsigned          m_number;
        Url                     m_url;
        XGSceneQt*              m_scene     = nullptr;
        XGViewQt*               m_view      = nullptr;
    };
}
