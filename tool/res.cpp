////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <filesystem>
#include <iostream>
#include <string_view>
#include <vector>
#include <yq/process/PluginLoader.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/core/Logging.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/text/match.hpp>
#include <yq/text/vsplit.hpp>
#include <yq/typedef/string_vectors.hpp>

using namespace yq;
using namespace yq::tachyon;

using string_view_span_t    = std::span<const std::string_view>;

struct ExecAPI {
    std::string_view            cmd;
    string_view_span_t          args;
    std::vector<ResourceCPtr>   res;
};


///////////////////////////////////////////////////////////////////////////////

bool cmd_help(ExecAPI&) 
{
    std::cout <<R"VOGON(
    res [cmd/options] <file...N>
    
    General tool for resource management; ie, coordinate transforms on meshes, inflating/shrinking images, etc.
    
    A simple reformatting can be done with (or even extraction with URL syntax)
    
        res MyImage.jpg save=MyImage.png
        
        
    Command syntax...
    
        cmd=arg,arg,arg,arg
        
)VOGON" ;
    return true;
}

bool cmd_save(ExecAPI& api)
{
    if(api.res.empty()){
        yError() << "Need a resource in order to save.";
        return false;
    }
    if(api.res.size() > 1){
        yError() << "Can only save ONE resource!";
        return false;
    }
    if(api.args.empty()){
        yError() << "Need a place to save it...";
        return false;
    }
    
    return api.res[0] -> save_to(api.args[0], {.collision = FileCollisionStrategy::Backup}) == std::error_code();
}

bool cmd_type(ExecAPI& api)
{
    for(auto& r : api.res){
        if(!r)
            continue;
            
        //  eventually the full info... for now...
        std::cout << r->metaInfo().name() << ": " << r->url() << '\n';
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////

typedef bool (*CmdFN)(ExecAPI&);

struct CmdInfo {
    const char*     name    = nullptr;
    CmdFN           fn      = nullptr;
} kCommands[] = {
    { "help", cmd_help },
    { "save", cmd_save },
    { "type", cmd_type }
};


///////////////////////////////////////////////////////////////////////////////

struct Cmd {
    std::string_view        cmd;
    string_view_vector_t    args;
    CmdFN                   fn      = nullptr;
};

//  parses the input as *IF* there's a command hit
Cmd parse_cmd(const char* txt)
{
    const char* eq  = strchr(txt, '=');
    if(!eq)
        return { .cmd=txt };
    
    Cmd ret;
    ret.cmd = std::string_view(txt, eq);
    
    vsplit(eq+1, ',', [&](std::string_view bit){
        ret.args.push_back(bit);
    });
    return ret;
}

CmdFN       lookup_cmd(std::string_view cmd)
{
   for(auto& ci : kCommands){
        if(is_similar(ci.name, cmd))
            return ci.fn;
    }
    return nullptr;
}


int main(int argc, char* argv[])
{
    ExecAPI     api;
    
    if(argc <= 1){
        cmd_help(api);
        
        std::cout << "\nCommand List:\n";
        for(auto& ci : kCommands)
            std::cout << "    " <<  ci.name << "\n";
        
        return 0;
    }
    
    log_to_std_error(LogPriority::Info);

    AppCreateInfo   aci;
    aci.vulkan.headless    = true;
    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    Meta::freeze();
    
    std::filesystem::path   input, output;
    std::vector<Cmd>        commands;
    for(int n=1;n<argc;++n){
        Cmd c   = parse_cmd(argv[n]);
        c.fn    = lookup_cmd(c.cmd);
        if(c.fn){
            commands.push_back(c);
            continue;
        }
        
        ResourceCPtr        rp  = Resource::resource_load((std::string_view) argv[n]);
        if(!rp)
            continue;
        
        api.res.push_back(rp);
    }
    
    yInfo() << "Loaded " << api.res.size() << " resource(s)";
    
    for(Cmd& c : commands){
        api.cmd     = c.cmd;
        api.args    = c.args;
        if(!(*c.fn)(api))
            break;
    }
    
    
    return 0;
}
