////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xml/XmlFile.hpp>
#include <yt/typedef/save.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    class SaveAsset;
    class SaveDelegate;
    class SaveObject;
    class SaveResource;
    class SaveTachyon;
    class SaveThread;

    class SaveXML : public XmlFile {
    public:

        SaveSPtr                save;

        static constexpr const char*  szExtension   = "tsx";
        static constexpr unsigned     kFormat       = 1;

        using XmlFile::write;   //< only to shut the compiler up
        using XmlFile::read;    //< only to shut the compiler up

        SaveXML();
        ~SaveXML();
        virtual std::error_code    read(const XmlDocument&, std::string_view fname) override;
        virtual std::error_code    write(XmlDocument&) const override;
        
        void        write(XmlNode&, asset_k,    const SaveAsset&) const;
        void        write(XmlNode&, delegate_k, const SaveDelegate&) const;
        void        write(XmlNode&, object_k,   const SaveObject&) const;
        void        write(XmlNode&, resource_k, const SaveResource&) const;
        void        write(XmlNode&, tachyon_k,  const SaveTachyon&) const;
        void        write(XmlNode&, thread_k,   const SaveThread&) const;
        
        std::error_code    read(const XmlNode&, asset_k);
        std::error_code    read(const XmlNode&, delegate_k);
        std::error_code    read(const XmlNode&, object_k);
        std::error_code    read(const XmlNode&, resource_k);
        std::error_code    read(const XmlNode&, tachyon_k);
        std::error_code    read(const XmlNode&, thread_k);
        std::error_code    read(const XmlNode&, variable_k);
    };
}
