////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGCanvasQt.hpp"
#include <yq/text/match.hpp>
#include <yq/xg/XGDocument.hpp>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <yq/gluon/graph/GraphScene.hpp>
#include <yq/gluon/graph/GraphView.hpp>


namespace yq::tachyon {
    static std::atomic<unsigned>    gCanvasNum{1};

    XGCanvasQt::XGCanvasQt(QWidget*parent) : 
        gluon::GraphicsCanvas(new gluon::GraphView(new gluon::GraphScene), parent), 
        m_number(gCanvasNum++)
    {
        m_view      = (gluon::GraphView*) gluon::GraphicsCanvas::view();
        m_scene     = (gluon::GraphScene*) gluon::GraphicsCanvas::scene();
        m_scene -> setParent(this);
        m_scene -> setSceneRect(QRectF(0,0,2048,2048));
    }
    
    XGCanvasQt::~XGCanvasQt()
    {
    }

    void        XGCanvasQt::clear()
    {
        m_scene -> clear();
        m_url   = {};
    }

    XGDocumentPtr           XGCanvasQt::get() const
    {
        return {};
        //return m_scene -> get();
    }
    
    void                    XGCanvasQt::set(const XGDocument& doc)
    {
        //m_scene -> set(doc);
        //m_url       = doc.url();
    }

    std::filesystem::path   XGCanvasQt::dirpath() const
    {
        return filepath().parent_path();
    }
    
    QString                 XGCanvasQt::dirname() const
    {
        return QString::fromStdString(dirpath().string());
    }

    std::filesystem::path XGCanvasQt::filepath() const
    {
        if(!is_similar(m_url.scheme, "file"))
            return {};
        if(!m_url.fragment.empty())
            return {};
        if(!m_url.query.empty())
            return {};
        return m_url.path;
    }

    QString XGCanvasQt::filename() const
    {
        return QString::fromStdString(filepath().string());
    }

    void    XGCanvasQt::updateTitle()
    {
        std::string s = to_string(m_url);
        if(s.empty()){
            setWindowTitle(tr("Unnamed:%1").arg(m_number));
        } else {
            setWindowTitle(QString::fromStdString(s));
        }
    }
}


#include "moc_XGCanvasQt.cpp"
