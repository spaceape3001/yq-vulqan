////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGPaletteQt.hpp"
#include <yq/gluon/core/Utilities.hpp>
#include <yq/text/match.hpp>
#include <yq/xg/XGElement.hpp>

using namespace yq::gluon;

namespace yq::tachyon {
    // Doing it this way as templates will be coming, so need the flexibility
    using palette_item_t = std::variant<const XGElementMeta*>;

    std::string_view    get_category(const palette_item_t&v)
    {
        if(auto p = std::get_if<const XGElementMeta*>(&v))
            return (*p) -> category();
        return "";
    }
    
    std::string_view    get_label(const palette_item_t&v)
    {
        if(auto p = std::get_if<const XGElementMeta*>(&v))
            return (*p) -> label();
        return "";
    }
    
    /*
    std::string_view    get_icon(const palette_item_t&v)
    {
        if(auto p = std::get_if<const XGElementMeta*>(&v))
            return (*p) -> icon();
        return "";
    }
    */
    
    bool                get_decision(const palette_item_t&v)
    {
        if(auto p = std::get_if<const XGElementMeta*>(&v))
            return (*p) -> decision();
        return "";
    }
    

    XGPaletteQt::XGPaletteQt(QWidget*parent) : PaletteWidget(parent)
    {
        setWindowTitle(tr("Palette"));
        _populate();
    }
    
    XGPaletteQt::~XGPaletteQt()
    {
    }

    void XGPaletteQt::_populate()
    {
        std::vector<palette_item_t> items;
        for(const XGElementMeta* xm : XGElementMeta::all()){
            if(xm->is_abstract())
                continue;
            items.push_back(xm);
        }
        
        //  templates go here
        
        std::stable_sort(items.begin(), items.end(), [](const palette_item_t& a, const palette_item_t& b) -> bool {
            return is_less_igCase(get_label(a), get_label(b));
        });
        
        for(auto& i : items){
            QString   cat       = qString(get_category(i));
            QString   label     = qString(get_label(i));
            
            
            //  icon TBD
            auto& it = category(cat).addItem(label); 
            it.setFlags(Qt::ItemIsDragEnabled);
        }
    }

}

#include "moc_XGPaletteQt.cpp"
