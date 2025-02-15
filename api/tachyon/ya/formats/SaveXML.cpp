////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveXML.hpp"
#include <yq/xml/XmlUtils.hpp>
#include <yt/errors.hpp>
#include <yq/strings.hpp>
#include <yt/io/Save.hpp>

namespace yq::tachyon {
    SaveXML::SaveXML()
    {
    }
    
    SaveXML::~SaveXML()
    {
    }
    
    std::error_code    SaveXML::read(const XmlDocument&, std::string_view fname) 
    {
        return errors::todo();
    }
    
    std::error_code    SaveXML::write(XmlDocument&) const 
    {
        return errors::todo();
    }
}

