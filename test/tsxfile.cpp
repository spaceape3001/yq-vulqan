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

namespace ut = boost::ut;
using namespace ut;
using namespace yq;
using namespace yq::tachyon;

Ref<SimpleSpatial³>     s_spatial;

void    write_simple_spatial()
{
    s_spatial   = new SimpleSpatial³;
    s_spatial -> set_position(Vector3D(1, 2, 3));
    s_spatial -> set_orientation(Quaternion3D(0.5, -0.5, 0.25, -0.25));
    s_spatial -> set_scale(Vector3D(1., -0.5, 3.0));
    
    SaveXML     sxml;
    sxml.save       = std::make_shared<Save>();
    sxml.save->insert(*s_spatial);
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

int main()
{
    log_to_std_output();
    Meta::init();
    configure_standand_asset_path();

    "SimpleWrite"_test  = []{ write_simple_spatial(); };
    "SimpleRead"_test   = []{ recreate_simple_spatial(); };

    return ut::cfg<>.run();
}
