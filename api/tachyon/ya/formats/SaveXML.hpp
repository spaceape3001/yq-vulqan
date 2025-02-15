////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xml/XmlFile.hpp>
#include <yt/typedef/save.hpp>

namespace yq::tachyon {
    class SaveXML : public XmlFile {
    public:

        SaveSPtr                save;

        static constexpr const char* szExtension    = "tsx";

        SaveXML();
        ~SaveXML();
        virtual std::error_code    read(const XmlDocument&, std::string_view fname) override;
        virtual std::error_code    write(XmlDocument&) const override;
    };
}
