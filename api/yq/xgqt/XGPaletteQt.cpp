////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGPaletteQt.hpp"
#include "XGNewMimeQt.hpp"
#include <yq/gluon/core/Utilities.hpp>
#include <yq/text/match.hpp>
#include <yq/xg/XGElement.hpp>
#include <yq/xg/XGManifest.hpp>
#include <yq/xg/XGNodeMeta.hpp>
#include <QMimeData>

using namespace yq::gluon;

namespace yq::tachyon {
    struct XGPaletteQt::Item : public PaletteWidget::Item {
        Item(const XGNodeMeta& v) : PaletteWidget::Item(qString(v.label)), m_node(v) 
        {
            setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
            
            // icons, colors...?
        }
        
        const XGNodeMeta  m_node;
    };

    XGPaletteQt::XGPaletteQt(QWidget*parent) : XGPaletteQt(nullptr, parent)
    {
    }
    
    XGPaletteQt::XGPaletteQt(const XGManifest& man, QWidget*parent) : XGPaletteQt(&man, parent)
    {
    }
    
    XGPaletteQt::XGPaletteQt(const XGManifest*man, QWidget*parent) : PaletteWidget(parent)
    {
        setWindowTitle(tr("Palette"));
        if(man){
            std::vector<XGNodeMeta> copy(man->m_nodes);
            _populate(copy);
        } else {
            XGManifestPtr   copy    = XGElementMeta::create_manifest();
            _populate(copy->m_nodes);
        }
    }

    XGPaletteQt::~XGPaletteQt()
    {
    }

    void XGPaletteQt::_populate(std::vector<XGNodeMeta>& nodes)
    {
        //static QIcon  s_node    = qIcon(
        std::stable_sort(nodes.begin(), nodes.end(), 
            [](const XGNodeMeta& a, const XGNodeMeta& b) -> bool{
                return is_less_igCase(a.label, b.label);
            }
        );
    
        for(auto& xn : nodes)
            category(qString(xn.category)).addItem(new Item(xn));
    }

    QMimeData*  XGPaletteQt::mimeData(const QList<QListWidgetItem*>&items) const
    {
        if(items.isEmpty()) 
            return nullptr;
        for(QListWidgetItem* lwi : items){
            if(Item*i = dynamic_cast<Item*>(lwi))
                return new XGNewMimeQt(i->m_node);
        }
        
        return nullptr;
    }

}

#include "moc_XGPaletteQt.cpp"
