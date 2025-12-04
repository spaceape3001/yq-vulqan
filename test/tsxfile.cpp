////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <yq/core/Logging.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/math/tolerance/Absolute.hpp>
#include <yq/tachyon/spatial/SimpleSpatial3.hpp>
#include <yq/tachyon/io/Save.hpp>
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
    g_spatial -> set_domain(*g_spatial);
}

void    write_simple_spatial()
{
    SavePtr     save = new Save;
    
    save->add(*g_spatial);
    
    expect(save->count(TACHYON) == 1);
    
    const TachyonSave*   tac = save->tachyon(g_spatial->id());
    
    expect(tac != nullptr);
    if(tac)
        expect(tac->properties.size() == 4);
    
    std::error_code ec  = save->save_to("simple.tsx", {.collision = FileCollisionStrategy::Overwrite });
    expect( ec == std::error_code() );
    if(ec != std::error_code())
        yInfo() << "Unable to save: " << ec.message();
}

void    recreate_simple_spatial()
{
    SaveCPtr       save = Save::IO::load("simple.tsx");
    expect( save.valid());
    if(!save){
        yInfo() << "Unable to load the test file";
        return;
    }
    
    expect(save->count(TACHYON) == 1);
    if(!save->tachyons.data.empty()){
        const TachyonSave&  sv  = save->tachyons.data[0];
        expect(sv.properties.contains("scale") == true);
        expect(sv.properties.contains("domain") == true);
        expect(sv.properties.contains("orientation") == true);
        expect(sv.properties.contains("position") == true);
    }
    
    TachyonPtrVector    result;
    std::error_code ec  = save->execute(result);
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
    expect(ss3->domain() == ss3->id());
}

int main(int argc, char* argv[])
{
    AppCreateInfo   aci;
    aci.log_cerr    = {};
    aci.log_cout    = LogPriority::Debug;
    Application app(argc, argv, aci);
    Meta::init();
    configure_standand_resource_path();
    
    create_spatial();

    "SimpleWrite"_test  = []{ write_simple_spatial(); };
    "SimpleRead"_test   = []{ recreate_simple_spatial(); };

    return ut::cfg<>.run();
}
