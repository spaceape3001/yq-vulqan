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
#include <yq/text/parse.hpp>
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
    using missing_key_attribute         = error_db::entry<"TSX is missing key attribute">;
    using invalid_key_attribute         = error_db::entry<"TSX has an invalid key attribute">;
    using invalid_prop_name_attribute   = error_db::entry<"TSX has an invalid property name attribute">;
    using missing_prop_name_attribute   = error_db::entry<"TSX has an missing property name attribute">;
    using invalid_prop_type_attribute   = error_db::entry<"TSX has an invalid property type attribute">;
    using invalid_resource_attribute       = error_db::entry<"TSX has an invalid tachyon resource attribute">;
    using missing_resource_url          = error_db::entry<"TSX has an missing resource URL">;
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
    using bad_url                       = error_db::entry<"TSX contains misformatted URL">;
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
    static constexpr const char*    szOrigin        = "o";
    static constexpr const char*    szParent        = "p";
    static constexpr const char*    szProperty      = "p";
    static constexpr const char*    szResource      = "r";
    //static constexpr const char*    szResources     = "rs";
    static constexpr const char*    szRoot          = "tsx";
    static constexpr const char*    szState         = "s";
    static constexpr const char*    szStdThread     = "st";
    static constexpr const char*    szTachyon       = "tac";
    static constexpr const char*    szThread        = "th";
    static constexpr const char*    szType          = "t";
    static constexpr const char*    szUse           = "use";
    static constexpr const char*    szUrl           = "u";
    //static constexpr const char*    szVariable      = "var";
    //static constexpr const char*    szVariables     = "vars";
    
    static constexpr unsigned     kFormat       = 1;

    ///////////////////////////////////////////////////////////////////////////////////////////
    //  LOADING

    static std::variant<std::error_code, uint64_t, std::string > _key(const XmlNode& xn)
    {
        std::string_view    k       = read_attribute(xn, szKey, x_string_view);
        std::string_view    i       = read_attribute(xn, szId, x_string_view);
        
        if(k.empty()){
            if(i.empty()){
                return errors::missing_key_attribute();
            } else {
                auto ix = to_uint64(i);
                if(!ix)
                    return ix.error();
                return *ix;
            }
        } else {
            if(i.empty()){
                return std::string(k);
            } else {
                return errors::invalid_key_attribute();
            }
        }
    }
    
    static std::variant<std::error_code, uint64_t, Any>         _value(const XmlNode& xn)
    {
        std::string_view    type    = read_attribute(xn, szType, x_string_view);
        if(type.empty()){   // it's an ID
            auto x  = x_uint64(xn);
            if(!x)
                return x.error();
            return *x;
        } else {
            const TypeMeta* tm      = TypeMeta::find(type);
            if(!tm)
                errors::invalid_type_attribute();
            
            Any     v(*tm);
            std::error_code ec  = read_xml_any(xn, v);
            if(ec != std::error_code())
                return ec;
            return v;
        }
    }
    
    #if 0
        //  Not sure why these aren't being resolved...  too generic generic???
    template <typename KC, typename IC>
    std::error_code  _kv(KC& kc, IC& ic, const XmlNode& xn)
    {
        auto k  = _key(xn);
        if(auto p = std::get_if<std::error_code>(&k))
            return *p;
            
        auto v  = _value(xn);
        if(auto p = std::get_if<std::error_code>(&v))
            return *p;
        
        if(auto p = std::get_if<std::string>(&k)){
            if(auto p2 = std::get_if<Any>(&v))
                kc.insert({*p, *p2});
            if(auto p2 = std::get_if<uint64_t>(&v))
                kc.insert({*p, *p2});
        } else if(auto p = std::get_if<uint64_t>(&k)){
            if(auto p2 = std::get_if<Any>(&v))
                ic.insert({*p, *p2});
            if(auto p2 = std::get_if<uint64_t>(&v))
                ic.insert({*p, *p2});
        }
        return {};
    }
    
    template <typename KC, typename IC>
    std::error_code  _kv(KC& kc, const XmlNode& xn)
    {
        auto k  = read_attribute(xn, szKey, x_string);
        if(k.empty())
            return errors::missing_key_attribute();
            
        auto v  = _value(xn);
        if(auto p = std::get_if<std::error_code>(&v))
            return *p;
        
        if(auto p2 = std::get_if<Any>(&v))
            kc.insert({k, *p2});
        if(auto p2 = std::get_if<uint64_t>(&v))
            kc.insert({k, *p2});
        return {};
    }
    #endif

    static std::error_code  _load(ObjectSave& sv, const XmlNode& xn)
    {
        sv.class_   = read_attribute(xn, szClass, x_string);
        std::string origin  = read_attribute(xn, szOrigin, x_string);
        if(!origin.empty())
            sv.origin   = origin;

        std::string url     = read_attribute(xn, szUrl, x_string);
        if(!url.empty()){
            auto x  = to_url_view(url);
            if(!x.good)
                return errors::bad_url();
            sv.origin  = copy(x.value);
        }
        
        for(const XmlNode* d = xn.first_node(); d; d = d->next_sibling()){
            if(d->name() == szProperty){
                auto k  = read_attribute(*d, szKey, x_string);
                if(k.empty())
                    return errors::missing_key_attribute();
                    
                auto v  = _value(*d);
                if(auto p = std::get_if<std::error_code>(&v))
                    return *p;
                
                if(auto p2 = std::get_if<Any>(&v))
                    sv.properties[k] = *p2;
                if(auto p2 = std::get_if<uint64_t>(&v))
                    sv.properties[k] = *p2;


                //std::error_code ec  = _kv(sv.properties, *d);
                //if(ec != std::error_code())
                    //return ec;
            }
        }
        return {};
    }

    static std::error_code  _load(StateSave& sv, const XmlNode& xn)
    {
        for(const XmlNode* d = xn.first_node(); d; d = d->next_sibling()){
            if(d->name() == szState){
                auto k  = _key(*d);
                if(auto p = std::get_if<std::error_code>(&k))
                    return *p;
                    
                auto v  = _value(*d);
                if(auto p = std::get_if<std::error_code>(&v))
                    return *p;
                
                if(auto p = std::get_if<std::string>(&k)){
                    if(auto p2 = std::get_if<Any>(&v))
                        sv.ustate.insert({*p, *p2});
                    if(auto p2 = std::get_if<uint64_t>(&v))
                        sv.ustate.insert({*p, *p2});
                } else if(auto p = std::get_if<uint64_t>(&k)){
                    if(auto p2 = std::get_if<Any>(&v))
                        sv.pstate.insert({*p, *p2});
                    if(auto p2 = std::get_if<uint64_t>(&v))
                        sv.pstate.insert({*p, *p2});
                }

                //std::error_code ec = _kv(sv.ustate, sv.pstate, *d);
                //if(ec != std::error_code())
                    //return ec;
            }
        }
        return {};
    }

    static std::error_code  _load(DelegateSave& sv, const XmlNode& xn)
    {
        std::error_code ec  = _load((ObjectSave&) sv, xn);
        if(ec != std::error_code())
            return ec;

        auto x  = read_attribute(xn, szId, x_uint64);
        if(!x)
            return x.error();
        sv.id       = *x;

        return _load((StateSave&) sv, xn);
    }

    static std::error_code  _load(TachyonSave& sv, const XmlNode& xn)
    {
        std::error_code ec  = _load((ObjectSave&) sv, xn);
        if(ec != std::error_code())
            return ec;

        auto x  = read_attribute(xn, szId, x_uint64);
        if(!x)
            return x.error();
        sv.id       = *x;
        
        std::string_view s   = read_attribute(xn, szParent, x_string_view);
        if(!s.empty()){
            auto ux = to_uint64(s);
            if(!ux)
                return ux.error();
            sv.parent   = *ux;
        }
            
        for(const XmlNode* d = xn.first_node(); d; d = d->next_sibling()){
            if(d->name() == szAttribute){
                auto k  = _key(*d);
                if(auto p = std::get_if<std::error_code>(&k))
                    return *p;
                    
                auto v  = _value(*d);
                if(auto p = std::get_if<std::error_code>(&v))
                    return *p;
                
                if(auto p = std::get_if<std::string>(&k)){
                    if(auto p2 = std::get_if<Any>(&v))
                        sv.uattrs[*p] = *p2;
                    if(auto p2 = std::get_if<uint64_t>(&v))
                        sv.uattrs[*p] = *p2;
                } else if(auto p = std::get_if<uint64_t>(&k)){
                    if(auto p2 = std::get_if<Any>(&v))
                        sv.pattrs[*p] = *p2;
                    if(auto p2 = std::get_if<uint64_t>(&v))
                        sv.pattrs[*p] = *p2;
                }

                //ec  = _kv(sv.uattrs, sv.pattrs, *d);
                //if(ec != std::error_code()) 
                    //return ec;
            } else if(d->name() == szChild){
                auto ix     = x_uint64(*d);
                if(!ix)
                    return ix.error();
                sv.children.push_back(*ix);
            } else if(d->name() == szDelegate){
                std::string k   = read_attribute(*d, szKey, x_string);
                if(k.empty())
                    return errors::missing_key_attribute();
            } else if(d->name() == szResource){
                std::string k   = read_attribute(*d, szKey, x_string);
                if(k.empty())
                    return errors::missing_key_attribute();
                std::string u   = x_string(*d);
                if(u.empty())
                    return errors::missing_resource_url();
                auto ux = to_url_view(u);
                if(!ux.good)
                    return errors::bad_url();
                sv.resources[k] = copy(ux.value);
            }
        }
        return _load((StateSave&) sv, xn);
    }

    static std::error_code  _load(ThreadSave& sv, const XmlNode& xn)
    {
        std::error_code ec  = _load((TachyonSave&) sv, xn);
        if(ec != std::error_code())
            return ec;
            
        for(const XmlNode* d = xn.first_node(); d; d = d->next_sibling()){
            // does nothing right now
        }
 
        return {};
    }
    
    template <typename T>
    static std::error_code _load(Save::SMap<T>& cc, const XmlNode& xn)
    {
        size_t  n   = cc.data.size();
        cc.data.push_back({});
        T& sv    = cc.data.back();
        std::error_code ec  = _load(sv, xn);
        if(ec != std::error_code())
            return ec;
        cc.byId[sv.id]   = n;
        return{};
    }

    static save_ptr_x      _load(const XmlDocument& doc, const Url& url)
    {
        const XmlNode*  root    = doc.first_node(szRoot);
        if(!root){
            tachyonError << "TSX cannot find root element in " << url;
            return errors::xml_no_root_element();
        }

        SavePtr     ss  = new Save;
        ss->set_url(url);
        
        for(const XmlNode*  data = root->first_node(); data; data = data->next_sibling()){
            if(data->name() == szDelegate){
                std::error_code ec = _load(ss->delegates, *data);
                if(ec != std::error_code())
                    return unexpected(ec);
            } else if(data->name() == szTachyon){
                std::error_code ec = _load(ss->tachyons, *data);
                if(ec != std::error_code())
                    return unexpected(ec);
            } else if(data->name() == szThread){
                std::error_code ec = _load(ss->threads, *data);
                if(ec != std::error_code())
                    return unexpected(ec);
            }
        }
    
        return ss;
    }
    
    ///////////////////////////////////////////////////////////////////////////////////////////
    //  SAVING

    static void             _save(const save_key_t& k, const save_value_t& v, XmlNode& xn)
    {
        if(auto p = std::get_if<uint32_t>(&k))
            write_attribute(xn, szId, *p);
        if(auto p = std::get_if<std::string>(&k))
            write_attribute(xn, szKey, *p);
        if(auto p = std::get_if<uint64_t>(&v)){
            write_x(xn, *p);
        } else if(auto p = std::get_if<Any>(&v)){
            write_attribute(xn, szType, p->type().name());
            write_xml_any(xn, *p);
        }
    }

    static void             _save(const ObjectSave& b, XmlNode& xn)
    {
        write_attribute(xn, szClass, b.class_);
        if(auto p = std::get_if<std::string>(&b.origin))
            write_attribute(xn, szOrigin, *p);
        if(auto p = std::get_if<Url>(&b.origin))
            write_attribute(xn, szUrl, to_string(*p));
        for(auto& itr : b.properties)
            _save(itr.first, itr.second, *xn.create_element(szProperty));
    }

    static void             _save(const StateSave& b, XmlNode& xn)
    {
        for(auto& itr : b.pstate)
            _save(itr.first, itr.second, *xn.create_element(szState));
        for(auto& itr : b.ustate)
            _save(itr.first, itr.second, *xn.create_element(szState));
    }
    
    static void             _save(const DelegateSave&b, XmlNode&xn)
    {
        _save((const ObjectSave&) b, xn);
        _save((const StateSave&) b, xn);
        write_attribute(xn, szId, b.id);
    }

    static void             _save(const TachyonSave&b, XmlNode&xn)
    {
        _save((const ObjectSave&) b, xn);
        _save((const StateSave&) b, xn);
        write_attribute(xn, szId, b.id);
        if(b.parent)
            write_attribute(xn, szParent, b.parent);
        if(auto p = std::get_if<uint64_t>(&b.owner))
            write_attribute(xn, szThread, *p);
        if(auto p = std::get_if<StdThread>(&b.owner))
            write_attribute(xn, szStdThread, *p);
            
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
        for(auto& itr : b.pattrs)
            _save(itr.first, itr.second, *xn.create_element(szAttribute));
        for(auto& itr : b.uattrs)
            _save(itr.first, itr.second, *xn.create_element(szAttribute));
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
