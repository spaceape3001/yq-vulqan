////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveXML.hpp"
#include <yq/xml/XmlUtils.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yt/io/Save.hpp>
#include <yt/io/save/SaveAsset.hpp>
#include <yt/io/save/SaveDelegate.hpp>
#include <yt/io/save/SaveResource.hpp>
#include <yt/io/save/SaveTachyon.hpp>
#include <yt/io/save/SaveThread.hpp>
#include <yq/text/format.hpp>
#include <yt/app/Application.hpp>
#include <yt/api/Delegate.hpp>
#include <yt/api/Resource.hpp>
#include <yt/api/Thread.hpp>

namespace yq::tachyon {
    static constexpr const char*    szApplication   = "application";
    static constexpr const char*    szAsset         = "asset";
    static constexpr const char*    szAssets        = "assets";
    static constexpr const char*    szDelegate      = "delegate";
    static constexpr const char*    szDelegates     = "delegates";
    static constexpr const char*    szClass         = "class";
    static constexpr const char*    szFormat        = "format";
    static constexpr const char*    szId            = "id";
    static constexpr const char*    szName          = "name";
    static constexpr const char*    szObject        = "object";
    static constexpr const char*    szProperty      = "property";
    static constexpr const char*    szResource      = "resource";
    static constexpr const char*    szRoot          = "tsx";
    static constexpr const char*    szTachyon       = "tachyon";
    static constexpr const char*    szThread        = "thread";
    static constexpr const char*    szType          = "type";
    static constexpr const char*    szVariable      = "variable";
    static constexpr const char*    szVariables     = "variables";

    namespace errors {
        using missing_root_element          = error_db::entry<"TSX is missing root element">;
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
        const XmlNode*  root    = doc.first_node(szRoot);
        if(!root){
            tachyonError << "TSX cannot find root element in " << fname;
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
            } else if(data->name() == szResource){
                std::error_code ec = read(*data, RESOURCE);
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
    
        return errors::todo();
    }

    std::error_code    SaveXML::read(const XmlNode&xml, asset_k)
    {
        return errors::todo();
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, delegate_k)
    {
        return errors::todo();
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, object_k)
    {
        return errors::todo();
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, resource_k)
    {
        return errors::todo();
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, tachyon_k)
    {
        return errors::todo();
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, thread_k)
    {
        return errors::todo();
    }
    
    std::error_code    SaveXML::read(const XmlNode&xml, variable_k)
    {
        return errors::todo();
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

            if(type.can_write_and_parse()){
                write_x(var, itr.second.writable());
                continue;
            }
            
            //  Try XML nodes....
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
            case SaveType::Resource:
                write(*(root.create_element(szResource)), RESOURCE, static_cast<const SaveResource&>(*itr.second));
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
        write(xml, OBJECT, obj);
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
                
            if(type.can_write_and_parse()){
                write_x(prop, p.value.writable());
                continue;
            }

            //  TODO ... XML nodes (and more extensive saving)
        }
    }
    
    void    SaveXML::write(XmlNode& xml, resource_k, const SaveResource& obj) const
    {
        write(xml, ASSET, obj);
    }
    
    void    SaveXML::write(XmlNode& xml, tachyon_k,  const SaveTachyon& obj) const
    {
        write(xml, OBJECT, obj);
    }
    
    void    SaveXML::write(XmlNode& xml, thread_k,   const SaveThread& obj) const
    {
        write(xml, TACHYON, obj);
    }
}

