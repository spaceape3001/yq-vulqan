////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveXML.hpp"
#include <yq/errors.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/resource/ResourceDriverAPI.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/io/Save.hpp>
#include <yq/xml/XmlAny.hpp>
#include <yq/xml/XmlUtils.hpp>
#include <filesystem>

#include <yq/resource/Resource.hxx>
#include <yq/net/Url.hpp>

namespace yq::errors {
    using missing_root_element          = error_db::entry<"TSX is missing root element">;
    using missing_type_attribute        = error_db::entry<"TSX is missing type attribute">;
    using invalid_type_attribute        = error_db::entry<"TSX has an invalid type attribute">;
    using missing_name_attribute        = error_db::entry<"TSX is missing name attribute">;
    using invalid_prop_name_attribute   = error_db::entry<"TSX has an invalid property name attribute">;
    using missing_prop_name_attribute   = error_db::entry<"TSX has an missing property name attribute">;
    using invalid_prop_type_attribute   = error_db::entry<"TSX has an invalid property type attribute">;
    using invalid_resource_attribute       = error_db::entry<"TSX has an invalid tachyon resource attribute">;
    using invalid_delegate_attribute    = error_db::entry<"TSX has an invalid tachyon delegate attribute">;
    using invalid_tachyon_attribute     = error_db::entry<"TSX has an invalid tachyon attribute">;
    using missing_class_attribute       = error_db::entry<"TSX is missing class attribute">;
    using invalid_class_attribute       = error_db::entry<"TSX has an invalid class attribute">;
    using invalid_owner_attribute       = error_db::entry<"TSX has an invalid owner attribute">;
    using not_resource_class               = error_db::entry<"TSX class attribute is not an resource">;
    using not_delegate_class            = error_db::entry<"TSX class attribute is not a delegate">;
    using not_tachyon_class             = error_db::entry<"TSX class attribute is not a tachyon">;
    using not_thread_class              = error_db::entry<"TSX class attribute is not a thread">;
    using invalid_id_property           = error_db::entry<"TSX property attribute has a bad ID">;
}

namespace yq::tachyon {
    static constexpr const char*    szApplication   = "app";
    static constexpr const char*    szAttribute     = "a";
    static constexpr const char*    szDelegate      = "d";
    //static constexpr const char*    szDelegates     = "ds";
    static constexpr const char*    szClass         = "c";
    static constexpr const char*    szChild         = "ch";
    //static constexpr const char*    szFile          = "file";
    static constexpr const char*    szFormat        = "fmt";
    static constexpr const char*    szId            = "i";
    static constexpr const char*    szKey           = "k";
    static constexpr const char*    szName          = "n";
    //static constexpr const char*    szObject        = "obj";
    //static constexpr const char*    szOwner         = "owner";
    static constexpr const char*    szParent        = "p";
    static constexpr const char*    szProperty      = "p";
    static constexpr const char*    szResource      = "r";
    //static constexpr const char*    szResources     = "rs";
    static constexpr const char*    szRoot          = "tsx";
    static constexpr const char*    szState         = "s";
    static constexpr const char*    szTachyon       = "tac";
    static constexpr const char*    szThread        = "th";
    static constexpr const char*    szType          = "t";
    static constexpr const char*    szUse           = "use";
    static constexpr const char*    szUrl           = "u";
    //static constexpr const char*    szVariable      = "var";
    //static constexpr const char*    szVariables     = "vars";
    
    static constexpr unsigned     kFormat       = 1;


    static save_ptr_x      _load(const XmlDocument& doc, const Url& url)
    {
        return errors::todo();
    }
    
    static void             _save(const ObjectSave& b, XmlNode& xn)
    {
        write_attribute(xn, szClass, b.type);
        if(auto p = std::get_if<std::string>(&b.origin))
            write_attribute(xn, szUrl, *p);
        if(auto p = std::get_if<Url>(&b.origin))
            write_attribute(xn, szUrl, to_string(*p));
        for(auto& itr : b.properties){
            XmlNode&    p   = *xn.create_element(szProperty);
            write_attribute(p, szKey, itr.first);
            write_attribute(p, szType, itr.second.type().name());
            write_xml_any(p, itr.second);
        }
        for(auto& itr : b.idprops){
            XmlNode&    p   = *xn.create_element(szProperty);
            write_attribute(p, szKey, itr.first);
            write_xn(p, itr.second);
        }
    }

    static void             _save(const DelegateSave&b, XmlNode&xn)
    {
        _save((const ObjectSave&) b, xn);
        write_attribute(xn, szId, b.id);
    }

    static void             _save(const TachyonSave&b, XmlNode&xn)
    {
        _save((const ObjectSave&) b, xn);
        write_attribute(xn, szId, b.id);
        if(b.parent)
            write_attribute(xn, szParent, b.parent);
        if(auto p = std::get_if<uint64_t>(&b.owner))
            write_attribute(xn, szThread, *p);
        if(auto p = std::get_if<StdThread>(&b.owner))
            write_attribute(xn, szThread, *p);
            
        for(auto id : b.children)
            write_child(xn, szChild, id);
        
        for(auto& itr : b.resources){
            XmlNode& r = *xn.create_element(szResource);
            write_attribute(r, szKey, itr.first);
            write_x(r, to_string(itr.second));
        }
        for(auto& itr : b.delegates){
            XmlNode& p = *xn.create_element(szDelegate);
            write_attribute(p, szKey, itr.first);
            write_x(p, itr.second);
        }
        for(auto& itr : b.pattrs){
            XmlNode& a = *xn.create_element(szAttribute);
            write_attribute(a, szId, itr.first);
            write_attribute(a, szType, itr.second.type().name());
            write_xml_any(a, itr.second);
        }
        for(auto& itr : b.uattrs){
            XmlNode& a = *xn.create_element(szAttribute);
            write_attribute(a, szKey, itr.first);
            write_attribute(a, szType, itr.second.type().name());
            write_xml_any(a, itr.second);
        }
        
        for(auto& itr : b.state){
            XmlNode& s = *xn.create_element(szState);
            write_attribute(s, szKey, itr.first);
            write_attribute(s, szType, itr.second.type().name());
            write_xml_any(s, itr.second);
        }
        for(auto& itr : b.ids){
            XmlNode& s = *xn.create_element(szState);
            write_attribute(s, szId, itr.first);
            write_x(s, itr.second);
        }
    }

    static std::error_code _save(const Save& save, XmlDocument&doc)
    {
        XmlNode&    root    = *(doc.create_element(szRoot));
        write_attribute(root, szApplication, Application::app_name());
        write_attribute(root, szFormat, to_string_view(kFormat));

        if(save.type != SaveType::General)
            write_attribute(root, szType, save.type);
        for(auto& u : save.uses){
            if(!u.empty())
                write_child(root, szUse, to_string(u));
        }
        for(auto& d : save.delegates.data)
            _save(d, *root.create_element(szDelegate));
        for(auto& th : save.threads.data)
            _save(th, *root.create_element(szThread));
        for(auto& th : save.tachyons.data)
            _save(th, *root.create_element(szTachyon));
        
        return {};
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    //  API INTERFACING/ADAPTERS TO THE ABOVE

    save_ptr_x      loadTSX(const XmlDocument& doc, const Url& url)
    {
        return _load(doc, url);
    }

    std::error_code saveTSX(const Save& save, XmlDocument&doc)
    {
        xml_start(doc);
        return _save(save, doc);
    }

    save_ptr_x      loadTSX(const std::filesystem::path& fp)
    {
        XmlDocument doc;
        std::error_code ec  = read_file(doc, fp);
        if(ec != std::error_code())
            return unexpected(ec);
        return loadTSX(doc, to_url(fp));
    }
    
    std::error_code saveTSX(const Save& save, const std::filesystem::path& fp)
    {
        XmlDocument doc;
        xml_start(doc);
        std::error_code ec  = saveTSX(save, doc);
        if(ec != std::error_code())
            return ec;
        return save_file(doc, fp);
    }
    
    static SavePtr         loadTSX_driver(const XmlDocument& doc, const ResourceLoadAPI&api)
    {
        auto x = loadTSX(doc, api.url());
        if(!x){
            tachyonWarning << "Unable to load (" << api.url() << "): " << x.error().message();
            return {};
        }
        return *x;
    }
    
    static std::error_code saveTSX_driver(const Save&save, XmlDocument&doc)
    {
        return _save(save, doc);
    }
    
    
    static void reg_tsxIO()
    {
        Save::IO::add_loader({.extensions={ "tsx" }}, loadTSX_driver);
        Save::IO::add_saver({.extensions={ "tsx" }}, saveTSX_driver);
    }
    
    YQ_INVOKE(reg_tsxIO();)
}
