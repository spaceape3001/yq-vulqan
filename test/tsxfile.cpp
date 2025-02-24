////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <yq/core/Logging.hpp>
#include <yt/application.hpp>
#include <yq/math/tolerance/Absolute.hpp>
#include <ya/spatials/SimpleSpatial3.hpp>
#include <yt/io/Save.hpp>
#include <ya/formats/SaveXML.hpp>
#include <yt/io/save/SaveTachyon.hpp>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

namespace ut = boost::ut;
using namespace ut;
using namespace yq;
using namespace yq::tachyon;

Ref<SimpleSpatial³>     g_spatial;

Quaternion3D            k_quat(0.5, -0.5, 0.25, -0.25);

void    create_spatial()
{
    g_spatial   = new SimpleSpatial³;
    g_spatial -> set_position(Vector3D(1, 2, 3));
    g_spatial -> set_orientation(k_quat);
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
    if(ec != std::error_code()){
        yInfo() << "Unable to save: " << ec.message();
    }
}

void    recreate_simple_spatial()
{
    SaveXML sxml;
    
    std::error_code ec = sxml.load("simple.tsx");
    expect( ec == std::error_code() );
    if(ec != std::error_code()){
        yInfo() << "Unable to load: " << ec.message();
        return ;
    }
    if(!sxml.save)
        return ;
    
    TachyonPtrVector    result;
    ec  = sxml.save->execute(result);
    expect( ec == std::error_code() );
    if(ec != std::error_code()){
        yInfo() << "Unable to execute: " << ec.message();
        return ;
    }
    
    expect( result.size() == 1 );
    if(result.empty())
        return ;
    
    SimpleSpatial³* ss3 = dynamic_cast<SimpleSpatial³*>(result[0].ptr());
    expect(ss3 != nullptr);
    if(!ss3)
        return ;
    
    Absolute tol(1e-5);
    expect(true == is_close(tol, ss3->position(), 1., 2., 3. ));
    expect(true == is_close(tol, ss3->orientation(), ~k_quat));
    expect(true == is_close(tol, ss3->scale(), 1.0, -0.5, 3.0));
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
