////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveXML.hpp"
#include <yq/asset/Asset.hpp>
#include <yq/xml/XmlUtils.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <tachyon/io/Save.hpp>
#include <tachyon/io/save/SaveAsset.hpp>
#include <tachyon/io/save/SaveDelegate.hpp>
#include <tachyon/io/save/SaveTachyon.hpp>
#include <tachyon/io/save/SaveThread.hpp>
#include <yq/text/chars.hpp>
#include <yq/text/format.hpp>
#include <yq/text/parse.hpp>
#include <tachyon/app/Application.hpp>
#include <yt/api/Delegate.hpp>
#include <yt/api/Thread.hpp>
#include <yt/api/meta/AssetProperty.hpp>
#include <yt/api/meta/DelegateProperty.hpp>

namespace yq::tachyon {
    static constexpr const char*    szApplication   = "application";
    static constexpr const char*    szAsset         = "asset";
    static constexpr const char*    szAssets        = "assets";
    static constexpr const char*    szDelegate      = "delegate";
    static constexpr const char*    szDelegates     = "delegates";
    static constexpr const char*    szClass         = "class";
    static constexpr const char*    szChild         = "child";
    static constexpr const char*    szFile          = "file";
    static constexpr const char*    szFormat        = "format";
    static constexpr const char*    szId            = "id";
    static constexpr const char*    szName          = "name";
    static constexpr const char*    szObject        = "object";
    static constexpr const char*    szOwner         = "owner";
    static constexpr const char*    szParent        = "parent";
    static constexpr const char*    szProperty      = "property";
    static constexpr const char*    szRoot          = "tsx";
    static constexpr const char*    szTachyon       = "tachyon";
    static constexpr const char*    szThread        = "thread";
    static constexpr const char*    szType          = "type";
    static constexpr const char*    szVariable      = "variable";
    static constexpr const char*    szVariables     = "variables";

    namespace errors {
        using missing_root_element          = error_db::entry<"TSX is missing root element">;
        using missing_type_attribute        = error_db::entry<"TSX is missing type attribute">;
        using invalid_type_attribute        = error_db::entry<"TSX has an invalid type attribute">;
        using missing_name_attribute        = error_db::entry<"TSX is missing name attribute">;
        using invalid_prop_name_attribute   = error_db::entry<"TSX has an invalid property name attribute">;
        using missing_prop_name_attribute   = error_db::entry<"TSX has an missing property name attribute">;
        using invalid_prop_type_attribute   = error_db::entry<"TSX has an invalid property type attribute">;
        using invalid_asset_attribute       = error_db::entry<"TSX has an invalid tachyon asset attribute">;
        using invalid_delegate_attribute    = error_db::entry<"TSX has an invalid tachyon delegate attribute">;
        using missing_class_attribute       = error_db::entry<"TSX is missing class attribute">;
        using invalid_class_attribute       = error_db::entry<"TSX has an invalid class attribute">;
        using invalid_owner_attribute       = error_db::entry<"TSX has an invalid owner attribute">;
        using not_asset_class               = error_db::entry<"TSX class attribute is not an asset">;
        using not_delegate_class            = error_db::entry<"TSX class attribute is not a delegate">;
        using not_tachyon_class             = error_db::entry<"TSX class attribute is not a tachyon">;
        using not_thread_class              = error_db::entry<"TSX class attribute is not a thread">;
    }

    SaveXML::SaveXML()
    {
    }
    
    SaveXML::~SaveXML()
    {
    }

    /////////////////////////// READING /////////////////////////
    
    std::error_code    SaveXML::read(const XmlDocument&doc, std::string_view fname) 
    {
        if(!save)
            save    = std::make_shared<Save>();
    
        const XmlNode*  root    = doc.first_node(szRoot);
        if(!root){
            tachyonError << "TSX cannot find root element in " << fname;
            return errors::xml_no_root_element();
            return errors::missing_root_element();
        }
        
        for(const XmlNode*  data = root->first_node(); data; data = data->next_sibling()){
            if(data->name() == szVariable){
                std::error_code ec = read(*data, VARIABLE);
                if(ec != std::error_code())
                    return ec;
            } else if(data->name() == szAsset){
                std::error_code ec = read(*data, ASSET);
                if(ec != std::error_code())
                    return ec;
            } else if(data->name() == szDelegate){
                std::error_code ec = read(*data, DELEGATE);
                if(ec != std::error_code())
                    return ec;
            } else if(data->name() == szObject){
                std::error_code ec = read(*data, OBJECT);
                if(ec != std::error_code())
                    return ec;
            } else if(data->name() == szTachyon){
                std::error_code ec = read(*data, TACHYON);
                if(ec != std::error_code())
                    return ec;
            } else if(data->name() == szThread){
                std::error_code ec = read(*data, THREAD);
                if(ec != std::error_code())
                    return ec;
            }
        }
    
        return {};
    }

    std::error_code    SaveXML::read(SaveAsset&sv,     asset_k, const XmlNode&xml)
    {
        return {};
    }
    
    std::error_code    SaveXML::read(SaveDelegate&sv,  delegate_k, const XmlNode&xml)
    {
        std::error_code ec  = read(sv, OBJECT, xml);
        if(ec != std::error_code())
            return ec;
        return {};
    }
    
    std::error_code    SaveXML::read(SaveObject&sv,    object_k, const XmlNode& xml)
    {
        if(!sv.info())
            return errors::null_pointer();
            
        for(const XmlNode* xc = xml.first_node(szProperty); xc; xc=xc->next_sibling(szProperty)){
            SaveProperty    prop;
        
            std::string     pn  = read_attribute(*xc, szName, x_string);
            if(pn.empty())
                return errors::missing_prop_name_attribute();
            prop.info = sv.info()->property(pn);
            if(!prop.info)
                return errors::invalid_prop_name_attribute();
            
            const TypeInfo* ti  = nullptr;
            std::string     tn  = read_attribute(*xc, szType, x_string);
            if(tn.empty()){
                ti      = &prop.info->type();
            } else {
                ti      = TypeInfo::find(tn);
            }
            if(!ti)
                return errors::invalid_prop_type_attribute();
                
            std::error_code     ec  = read(prop.value, *xc, *ti);
            if(ec != std::error_code())
                return ec;
            
            sv.append(std::move(prop));
        }
        return {};
    }
    
    std::error_code    SaveXML::read(SaveTachyon&sv,   tachyon_k, const XmlNode& xml)
    {
        if(!sv.info())
            return errors::null_pointer();

        std::string parent      = read_attribute(xml, szParent, x_string);
        if(!parent.empty()){
            auto x  = to_uint64(parent);
            if(!x)
                return x.error();
            sv.set_parent(*x);
        }
        
        std::string owner       = read_attribute(xml, szOwner, x_string);
        if(!owner.empty()){
            if(is_alpha(owner[0])){
                bool    ok  = false;
                StdThread   st(owner, &ok);
                if(!ok)
                    return errors::invalid_owner_attribute();
                sv.set_owner(st);
            } else {
                auto x = to_uint64(owner);
                if(!x)
                    return x.error();
                sv.set_owner(*x);
            }
        }
    
        std::error_code ec  = read(sv, OBJECT, xml);
        if(ec != std::error_code())
            return ec;
        
        for(const XmlNode* xc = xml.first_node(szChild); xc; xc=xc->next_sibling(szChild)){
            uint64_x       idv = x_uint64(*xc);
            if(!idv)
                return idv.error();
            
        }
            
        for(const XmlNode* xc = xml.first_node(szAsset); xc; xc=xc->next_sibling(szAsset)){
            std::string     pn  = read_attribute(*xc, szName, x_string);
            if(pn.empty())
                return errors::invalid_asset_attribute();

            const AssetProperty* prop   = sv.info()->asset(pn);
            if(!prop)
                return errors::invalid_asset_attribute();
            
            uint64_x      idv = x_uint64(*xc);
            if(!idv)
                return idv.error();
            
            SaveAsset*  ass = save->asset(*idv);
            if(!ass)
                return errors::invalid_asset_attribute();

            sv.append(SaveTachyon::asset_t{prop, ass});
        }
            
        for(const XmlNode* xc = xml.first_node(szDelegate); xc; xc=xc->next_sibling(szDelegate)){
            std::string     pn  = read_attribute(*xc, szName, x_string);
            if(pn.empty())
                return errors::invalid_delegate_attribute();

            const DelegateProperty* prop   = sv.info()->delegate(pn);
            if(!prop)
                return errors::invalid_delegate_attribute();
            
            uint64_x      idv = x_uint64(*xc);
            if(!idv)
                return idv.error();
            
            SaveDelegate*  ass = save->delegate(*idv);
            if(!ass)
                return errors::invalid_delegate_attribute();

            sv.append(SaveTachyon::delegate_t{prop, ass});
        }
        
        return {}; 
    }
    
    std::error_code    SaveXML::read(SaveThread&sv,    thread_k, const XmlNode& xml)
    {
        std::error_code ec  = read(sv, TACHYON, xml);
        if(ec != std::error_code())
            return ec;
            
        return {};  // TODO
    }

    std::error_code    SaveXML::read(const XmlNode&xml, asset_k)
    {
        std::filesystem::path   fp(x_string(xml));
    
        const XmlAttribute* xclass  = xml.first_attribute(szClass);
        if(!xclass)
            return errors::missing_class_attribute();

        std::string cname   = x_string(*xclass);
        const ObjectInfo*   cinfo   = ObjectInfo::find(cname);
        if(!cinfo)
            return errors::invalid_class_attribute();
        
        const AssetInfo*  tinfo   = dynamic_cast<const AssetInfo*>(cinfo);
        if(!tinfo)
            return errors::not_asset_class();
        return read(*(save->create(tinfo, fp)), ASSET, xml);
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, delegate_k)
    {
        const XmlAttribute* xclass  = xml.first_attribute(szClass);
        if(!xclass)
            return errors::missing_class_attribute();
        std::string cname   = x_string(*xclass);
        const ObjectInfo*   cinfo   = ObjectInfo::find(cname);
        if(!cinfo)
            return errors::invalid_class_attribute();
        
        const DelegateInfo*  tinfo   = dynamic_cast<const DelegateInfo*>(cinfo);
        if(!tinfo)
            return errors::not_tachyon_class();
        return read(*(save->create(tinfo)), DELEGATE, xml);
        
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, object_k)
    {
        return errors::todo();  // We don't support full object save/load (yet)
        
    #if 0
        const XmlAttribute* xclass  = xml.first_attribute(szClass);
        if(!xclass)
            return errors::missing_class_attribute();
        
        std::string cname   = x_string(*xclass);
        const ObjectInfo*   cinfo   = ObjectInfo::find(cname);
        if(!cinfo)
            return errors::invalid_class_attribute();

        return read(*(save->create(cinfo)), OBJECT, xml);
    #endif
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, tachyon_k)
    {
        const XmlAttribute* xclass  = xml.first_attribute(szClass);
        if(!xclass)
            return errors::missing_class_attribute();
        
        std::string cname   = x_string(*xclass);
        const ObjectInfo*   cinfo   = ObjectInfo::find(cname);
        if(!cinfo)
            return errors::invalid_class_attribute();
        
        const TachyonInfo*  tinfo   = dynamic_cast<const TachyonInfo*>(cinfo);
        if(!tinfo)
            return errors::not_tachyon_class();
        return read(*(save->create(tinfo)), TACHYON, xml);
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, thread_k)
    {
        const XmlAttribute* xclass  = xml.first_attribute(szClass);
        if(!xclass)
            return errors::missing_class_attribute();
        
        std::string cname   = x_string(*xclass);
        const ObjectInfo*   cinfo   = ObjectInfo::find(cname);
        if(!cinfo)
            return errors::invalid_class_attribute();
        
        const ThreadInfo*  tinfo   = dynamic_cast<const ThreadInfo*>(cinfo);
        if(!tinfo)
            return errors::not_tachyon_class();
            
        return read(*(save->create(tinfo)), THREAD, xml);
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, variable_k)
    {
        const XmlAttribute*     xname   = xml.first_attribute(szName);
        if(!xname)
            return errors::missing_name_attribute();
    
        const XmlAttribute* xa  = xml.first_attribute(szType);
        if(!xa)
            return errors::missing_type_attribute();
        const TypeInfo* type    = TypeInfo::find(xa->value());
        if(!type)
            return errors::invalid_type_attribute();
        
        Any             value;
        std::error_code ec = read(value, xml, *type);
        if(ec != std::error_code())
            return ec;
        save->add_variable(x_string(*xname), std::move(value));
        return {};

    }
    
    std::error_code    SaveXML::read(Any& value, const XmlNode&xml, const TypeInfo& type)
    {
        if(type.can_write_and_parse())
            return value.parse(type, x_string(xml));

        //  TODO (ie structured types)
        return errors::todo();  // TODO
    }


    /////////////////////////// WRITING /////////////////////////
    
    std::error_code    SaveXML::write(XmlDocument&doc) const 
    {
        if(!save)
            return errors::null_pointer();
            
        XmlNode&    root    = *(doc.create_element(szRoot));
        root.create_attribute(szApplication, Application::app_name());
        root.create_attribute(szFormat, to_string_view(kFormat));
        for(auto& itr : save->variables()){
            const TypeInfo& type   = itr.second.type();
            XmlNode&    var = *(root.create_element(szVariable));
            var.create_attribute(szName, itr.first);
            var.create_attribute(szType, type.name());
            write(var, itr.second);
        }
        
        for(auto& itr : save->objects()){
            switch(itr.second->saveType()){
            case SaveType::Asset:
                write(*(root.create_element(szAsset)), ASSET, static_cast<const SaveAsset&>(*itr.second));
                break;
            case SaveType::Delegate:
                write(*(root.create_element(szDelegate)), DELEGATE, static_cast<const SaveDelegate&>(*itr.second));
                break;
            case SaveType::Object:
                write(*(root.create_element(szObject)), OBJECT, *itr.second);
                break;
            case SaveType::Tachyon:
                write(*(root.create_element(szTachyon)), TACHYON, static_cast<const SaveTachyon&>(*itr.second));
                break;
            case SaveType::Thread:
                write(*(root.create_element(szThread)), THREAD, static_cast<const SaveThread&>(*itr.second));
                break;
            }
        }
        
        return {};
    }

    void    SaveXML::write(XmlNode& xml, asset_k,    const SaveAsset& obj) const
    {
        write_x(xml, obj.filepath().string());
    }
    
    void    SaveXML::write(XmlNode& xml, delegate_k, const SaveDelegate& obj) const
    {
        write(xml, OBJECT, obj);
    }
    
    void    SaveXML::write(XmlNode& xml, object_k,   const SaveObject& obj) const
    {
        xml.create_attribute(szClass, obj.info()->name());
        for(auto& p : obj.properties()){
            const TypeInfo& type    = p.value.type();
            bool    same            = type.id() == p.info->type().id();
            if(same && p.info->is_default(p.value)) // not regurgitating default values
                continue;

            XmlNode& prop   = *(xml.create_element(szProperty));
            prop.create_attribute(szName, p.info->name());
            if(!same){
                prop.create_attribute(szType, type.name());
            }
            
            write(prop, p.value);
        }
    }

    void    SaveXML::write(XmlNode&xml, const Any& value) const
    {
        const TypeInfo& type    = value.type();
        if(type.can_write_and_parse()){
            write_x(xml, value.writable());
            return;
        }
        
        //  TODO ... XML nodes (and more extensive saving)
    }
    
    void    SaveXML::write(XmlNode& xml, tachyon_k,  const SaveTachyon& obj) const
    {
        write(xml, OBJECT, obj);
        
        if(const SaveTachyon* parent   = save->tachyon(obj.parent())){
            write_attribute(xml, szParent, parent->remap());
        }
        
        if(auto p = std::get_if<uint64_t>(&obj.owner())){
            if(const SaveThread*th = save->thread(*p)){
                write_attribute(xml, szOwner, th->remap());
            }
        }
        if(auto p = std::get_if<StdThread>(&obj.owner())){
            write_attribute(xml, szOwner, *p);
        }

        for(uint64_t i : obj.children()){
            if(const SaveTachyon* tc = save->tachyon(i)){
                write_child(xml, szChild, tc->remap());
            }
        }
        
        
        for(auto& p : obj.assets()){
            XmlNode&    prop    = *(xml.create_element(szAsset));
            prop.create_attribute(szName, p.info->name());
            write_x(prop, p.asset->remap());
        }

        for(auto& p : obj.delegates()){
            XmlNode&    prop    = *(xml.create_element(szDelegate));
            prop.create_attribute(szName, p.info->name());
            write_x(prop, p.delegate->remap());
        }
    }
    
    void    SaveXML::write(XmlNode& xml, thread_k,   const SaveThread& obj) const
    {
        write(xml, TACHYON, obj);
    }
}

