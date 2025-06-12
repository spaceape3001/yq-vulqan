////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraScene.hpp"

#include <yq/color/colors.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/TetrahedronData.hpp>
#include <yq/shape/TriangleData.hpp>

#include <tachyon/camera/SpaceCamera.hpp>

#include <tachyon/rendered/Billboard3.hpp>
#include <tachyon/rendered/ImageQuad3.hpp>
#include <tachyon/rendered/Quadrilateral3.hpp>
#include <tachyon/rendered/SkyBox3.hpp>
#include <tachyon/rendered/ColorTriangle3.hpp>
#include <tachyon/rendered/Tetrahedron3.hpp>

#include <tachyon/api/Scene3InfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hxx>
#include <yq/typedef/string_initlists.hpp>

using namespace yq;
using namespace yq::tachyon;

YQ_TACHYON_IMPLEMENT(CameraScene)

const auto  NorthData = TetrahedronData<ColorVertex3D>{
    {{  0.,  1.,  0. }, color::White },
    {{ -1., -1., -1. }, color::Blue },
    {{  1., -1., -1. }, color::Blue },
    {{  0.,  0.,  1. }, color::Blue }
};

const auto  SouthData = TetrahedronData<ColorVertex3D>{
    {{  0.,  1.,  0. }, color::White },
    {{ -1., -1., -1. }, color::Yellow },
    {{  1., -1., -1. }, color::Yellow },
    {{  0.,  0.,  1. }, color::Yellow }
};

const auto  EastData = TetrahedronData<ColorVertex3D>{
    {{  1.,  0.,  0. }, color::White },
    {{ -1., -1., -1. }, color::Red },
    {{ -1.,  1., -1. }, color::Red },
    {{  0.,  0.,  1. }, color::Red }
};

const auto  WestData = TetrahedronData<ColorVertex3D>{
    {{ -1.,  0.,  0. }, color::White },
    {{  1., -1., -1. }, color::Cyan },
    {{  1.,  1., -1. }, color::Cyan },
    {{  0.,  0.,  1. }, color::Cyan }
};

const auto  TopData = TetrahedronData<ColorVertex3D>{
    {{  0.,  0.,  1. }, color::White },
    {{ -1., -1., -1. }, color::Green },
    {{  1., -1., -1. }, color::Green },
    {{  0.,  1., -1. }, color::Green }
};

const auto  BottomData = TetrahedronData<ColorVertex3D>{
    {{  0.,  0., -1. }, color::White },
    {{ -1., -1.,  1. }, color::Magenta },
    {{  1., -1.,  1. }, color::Magenta },
    {{  0.,  1.,  1. }, color::Magenta }
};

const auto  TriData   = TriangleData<ColorVertex2D> {
    { {1.0,1.0}, color::Red },
    { {0., -1}, color::White },
    { {-1., 1.}, color::Blue }
};


const auto QuadData = QuadrilateralData<ColorVertex2D> {
    { {-1.0, 1.0}, color::Green },
    { {1.0, 1.0}, color::Blue },
    { {0.5, -1.0}, color::Yellow },
    { {-0.5, -1.0}, color::Red }
};

CameraScene::CameraScene() 
{
}

CameraScene::~CameraScene()
{
}

Execution  CameraScene::setup(const Context&ctx)
{
    if(!m_init){

        //SpaceCamera*   sc  = create_child<SpaceCamera>();
        //sc->set_near(0.001);
        //sc->set_far(2.000);
        
        SkyBox³::Param  p;
        //p.camera    = sc->id();
        
        SkyBox³* sky     = create_child<SkyBox³>(
            string_view_initializer_list_t{ 
                "sdk/camera/NORTH.JPG",
                "sdk/camera/SOUTH.JPG",
                "sdk/camera/EAST.JPG",
                "sdk/camera/WEST.JPG",
                "sdk/camera/DOWN.JPG",
                "sdk/camera/UP.JPG" 
            },
            p
        );
        
        //  Bottom box (so +Z)
        ImageQuad³* iq  = nullptr;
        
        #if 0
        iq = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/DOWN.JPG");
        iq->make_simple_spatial(
            { 0., 0., 15. },
            Quaternion3D(IDENTITY)
        );
        #endif
        
        #if 0
        //  Top box (so -Z)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/UP.JPG");
        iq->make_simple_spatial(
            { 0., 0., -15. },
            Quaternion3D(CCW, X, (Radian) 180._deg)
        );        
        #endif

        #if 0
        //  North box (so +X)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/NORTH.JPG");
        iq->make_simple_spatial(
            { 15., 0., 0. },
            Quaternion3D(CCW, Y, 90._deg) * Quaternion3D(CCW, Z, 90._deg)
        );        
        #endif
        
        #if 0
        //  South box (so -X)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/SOUTH.JPG");
        iq->make_simple_spatial(
            { -15., 0., 0. },
            Quaternion3D(CCW, Y, -90._deg) * Quaternion3D(CCW, Z,  -90._deg)
        );        
        #endif
    
        #if 0
        //  East box (so +Y)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/EAST.JPG");
        iq->make_simple_spatial(
            { 0., 15., 0. },
            Quaternion3D(CCW, X, -90._deg) * Quaternion3D(CCW, Z, 180._deg )
        );        
        #endif
        
        #if 0
        //  West box (so -Y)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/WEST.JPG");
        iq->make_simple_spatial(
            { 0., -15., 0. },
            Quaternion3D(CCW, X, 90._deg) 
        );   
        #endif
        
        //  Something in the NE corner
        Billboard³* bq  = create_child<Billboard³>(
            AxBox2D(Vector2D(-1, -1), Vector2D(1, 1)), 
            "sdk/camera/swirl.png"
        );
        bq->make_simple_spatial(
            { 14., 14., 0. }
        );

        Triangle³*   tri    = create_child<ColorTriangle³>(TriData);
        tri->make_simple_spatial(ZERO, IDENTITY, Vector3D(ALL, 0.5));


        // north BLUE
        Rendered³*    dir     = create_child<Tetrahedron³>(NorthData);
        dir -> make_simple_spatial({15., 0., 0. });

        // south YELLOW
        dir     = create_child<Tetrahedron³>(SouthData);
        dir -> make_simple_spatial({-15., 0., 0. });
            
        dir     = create_child<Tetrahedron³>(EastData);
        dir -> make_simple_spatial({0., 15., 0. });

        dir     = create_child<Tetrahedron³>(WestData);
        dir -> make_simple_spatial({0., -15., 0. });
        
        dir     = create_child<Tetrahedron³>(TopData);
        dir -> make_simple_spatial({0., 0., -15. });
        
        // MAGENTA
        dir     = create_child<Tetrahedron³>(BottomData);
        dir -> make_simple_spatial({0., 0., 15. });
        
        Quadrilateral³* quad = create_child<Quadrilateral³>(QuadData);
        quad->make_simple_spatial(
            { 0.5, 0.5, 0. },
            Quaternion3D(CCW, Z, (Radian) 45._deg ),
            Vector3D(ALL, 0.5)
        );
        
        m_init  = true;
    }
    return SimpleScene::setup(ctx);
}
    
void CameraScene::init_info()
{
    auto w = writer<CameraScene>();
    w.description("Camera SDK Example Scene");
}

