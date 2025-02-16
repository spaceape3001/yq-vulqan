////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <yq/core/Logging.hpp>
#include <yt/application.hpp>
#include <ya/spatials/SimpleSpatial3.hpp>
#include <yt/io/Save.hpp>
#include <ya/formats/SaveXML.hpp>
#include <yt/io/save/SaveTachyon.hpp>

namespace ut = boost::ut;
using namespace ut;
using namespace yq;
using namespace yq::tachyon;

Ref<SimpleSpatial³>     g_spatial;

void    create_spatial()
{
    g_spatial   = new SimpleSpatial³;
    g_spatial -> set_position(Vector3D(1, 2, 3));
    g_spatial -> set_orientation(Quaternion3D(0.5, -0.5, 0.25, -0.25));
    g_spatial -> set_scale(Vector3D(1., -0.5, 3.0));
}


void    write_simple_spatial()
{
    SaveXML     sxml;
    
    sxml.save       = std::make_shared<Save>();
    sxml.save->insert(*g_spatial);
    
    expect(sxml.save->count(OBJECT) == 1);
    const SaveTachyon*   tac = sxml.save->tachyon(g_spatial->id());
    
    expect(tac != nullptr);
    if(tac){
        expect(tac->count(PROPERTY) == 3);
    }
    
    std::error_code ec  = sxml.save_to("simple.tsx");
    expect( ec == std::error_code() );
}

void    recreate_simple_spatial()
{
    SaveXML sxml;
    
    std::error_code ec = sxml.load("simple.tsx");
    expect( ec == std::error_code() );
    if(!sxml.save)
        return ;

    
}

int main(int argc, char* argv[])
{
    AppCreateInfo   aci;
    Application app(argc, argv, aci);
    log_to_std_output();
    Meta::init();
    configure_standand_asset_path();
    
    create_spatial();

    "SimpleWrite"_test  = []{ write_simple_spatial(); };
    "SimpleRead"_test   = []{ recreate_simple_spatial(); };

    return ut::cfg<>.run();
}
