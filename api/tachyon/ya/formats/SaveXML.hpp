////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xml/XmlFile.hpp>
#include <yt/io/Save.hpp>

namespace yq::tachyon {
    class SaveXML : public XmlFile {
    public:

        static constexpr const char* szExtension    = "tsx";

        //! Loads the xml (assumes it's already clear)
        std::error_code  load_xml(const std::filesystem::path&);
        std::error_code  save_xml(const std::filesystem::path&) const;
    };
}
