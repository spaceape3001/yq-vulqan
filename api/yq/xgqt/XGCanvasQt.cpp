////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGCanvasQt.hpp"
#include "XGSceneQt.hpp"
#include "XGViewQt.hpp"
#include <yq/text/match.hpp>
#include <yq/xg/XGDocument.hpp>
#include <QHBoxLayout>
#include <QVBoxLayout>



namespace yq::tachyon {
    static std::atomic<unsigned>    gCanvasNum{1};

    XGCanvasQt::XGCanvasQt(QWidget*parent) : XGCanvasQt({}, parent)
    {
    }
    
    XGCanvasQt::XGCanvasQt(XGDocumentPtr doc, QWidget*parent) : 
        gluon::GraphicsCanvas(new XGViewQt(new XGSceneQt( doc )), parent), 
        m_number(gCanvasNum++)
    {
        m_view      = (XGViewQt*) gluon::GraphicsCanvas::view();
        m_scene     = (XGSceneQt*) gluon::GraphicsCanvas::scene();
        m_scene -> setParent(this);
        m_doc       = m_scene -> document();

        updateTitle();
    }
    
    XGCanvasQt::~XGCanvasQt()
    {
    }

    std::filesystem::path   XGCanvasQt::dirpath() const
    {
        std::filesystem::path   fp  = filepath();
        if(fp.empty())  
            return {};
        return fp.parent_path();
    }
    
    QString                 XGCanvasQt::dirname() const
    {
        return QString::fromStdString(dirpath().string());
    }

    std::filesystem::path XGCanvasQt::filepath() const
    {
        if(!m_doc)  [[unlikely]]
            return {};
        
        auto& u = m_doc->url();
        if(!is_similar(u.scheme, "file"))
            return {};
        if(!u.fragment.empty())
            return {};
        if(!u.query.empty())
            return {};
        return u.path;
    }

    QString XGCanvasQt::filename() const
    {
        return QString::fromStdString(filepath().string());
    }

    void    XGCanvasQt::updateTitle()
    {
        std::string s = to_string(m_doc->url());
        if(s.empty()){
            setWindowTitle(tr("Unnamed:$1").arg(m_number));
        } else {
            setWindowTitle(QString::fromStdString(s));
        }
    }
}


#include "moc_XGCanvasQt.cpp"
