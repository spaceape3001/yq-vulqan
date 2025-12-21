////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <yq/container/ByteArray.hpp>
#include <yq/core/Logging.hpp>
#include <yq/file/FileUtils.hpp>
#include <yq/meta/Meta.hpp>
#include <yq/text/format.hpp>
#include <yq/text/match.hpp>
#include <yq/text/vsplit.hpp>
#include <yq/xml/XmlUtils.hpp>

#include <algorithm>
#include <fstream>
#include "rapidxml.hpp"

using namespace yq;

struct Struct {
    std::string name, stype;
};

std::vector<Struct>     gStructs;
std::set<std::string>   gListed;

#if 0
bool    scan_vulkan(const std::filesystem::path& inFile)
{
    std::
}
#endif

bool    scan_in(const std::filesystem::path& inFile)
{
    ByteArray data    = file_bytes(inFile);
    if(data.empty()){
        yError() << "Unable to load '" << inFile << "'";
        return false;
    }
    
    XmlDocument doc;
    std::error_code ec = parse_xml(doc, data);
    if(ec != std::error_code()){
        yError() << "Unable to read '" << inFile << "': " << ec.message();
        return false;
    }

    
    const XmlNode*  xReg    = doc.first_node("registry");
    if(!xReg){
        yError() << "Lacks registry";
        return false;
    }
    
    const XmlNode*  xTypes = xReg->first_node("types");
    if(!xTypes){
        yError() << "Lacks types";
        return false;
    }

    for(const XmlNode* x = xTypes->first_node("type"); x; x = x->next_sibling("type")){
        if(!is_similar("struct", read_attribute(*x, "category", x_string)))
            continue;
        
        Struct  s;
        s.name  = read_attribute(*x, "name", x_string);
        
        for(const XmlNode* m = x->first_node("member"); m; m=m->next_sibling("member")){
            std::string    values  = read_attribute(*m, "values", x_string);
            if(!values.empty()){
                s.stype     = values;
                break;
            }
        }
        
        if(!s.stype.empty())
            gStructs.push_back(s);
    }

    yInfo() << "We have " << gStructs.size() << " structures";
    return true;
}

void write_out(const std::filesystem::path& outFile)
{
    if(file_exists(outFile))
        file_backup(outFile.c_str());
        
    std::ofstream   fout(outFile);
    fout << R"VOGON(
////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  WARNING!  WARNING!  WARNNG!  WARNING!
//  This header file is AUTO-GENERATED, changes will be CLOBBERED

#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
)VOGON";
    
    for(auto& s : gStructs){
        if(!gListed.contains(s.name))
            continue;
    
        std::string qname   = s.name;
        qname[1] = 'q';
        fout << "    struct " << qname << " : public " << s.name << " {\n"
             << "        " << qname << "() : " << s.name << "{}\n"
             << "        {\n"
             << "            sType = " << s.stype << ";\n"
             << "        }\n"
             << "    };\n"
             << "\n";
    }

    fout << R"VOGON(
}
)VOGON";
}

int main(int argc, char* argv[])
{
    if(argc<3){
        std::cout << "Usage: vx_structures <vulkan-xml> <header>\n";
        return 0;
    }
    
    log_to_std_error();
    
    Meta::freeze();
    
    if(!scan_in(argv[1]))
        return 0;

    std::sort(gStructs.begin(), gStructs.end(), [](const Struct& a, const Struct& b) -> bool {
        return a.name < b.name;
    });
    
    write_out(argv[2]);
    return 0;
    
}
