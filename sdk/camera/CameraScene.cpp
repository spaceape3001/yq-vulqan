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

#include <ya/rendereds/Billboard3.hpp>
#include <ya/rendereds/ImageQuad3.hpp>
#include <ya/rendereds/Quadrilateral3.hpp>
#include <ya/rendereds/Triangle3.hpp>
#include <ya/rendereds/Tetrahedron3.hpp>

#include <yt/3D/Scene3InfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hxx>

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

CameraScene::CameraScene() : SimpleScene³()
{
}

CameraScene::~CameraScene()
{
}

Execution  CameraScene::setup(const Context&ctx)
{
    if(!m_init){
        
        //  Bottom box (so +Z)
        ImageQuad³* iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/DOWN.JPG");
        iq->make_simple_spatial(
            { 0., 0., 15. },
            Quaternion3D(IDENTITY)
        );
        
        //  Top box (so -Z)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/UP.JPG");
        iq->make_simple_spatial(
            { 0., 0., -15. },
            Quaternion3D(CCW, X, (Radian) 180._deg)
        );        

        //  North box (so +X)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/NORTH.JPG");
        iq->make_simple_spatial(
            { 15., 0., 0. },
            Quaternion3D(CCW, Y, 90._deg) * Quaternion3D(CCW, Z, 90._deg)
        );        
        
        //  South box (so -X)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/SOUTH.JPG");
        iq->make_simple_spatial(
            { -15., 0., 0. },
            Quaternion3D(CCW, Y, -90._deg) * Quaternion3D(CCW, Z,  -90._deg)
        );        
    
        //  East box (so +Y)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/EAST.JPG");
        iq->make_simple_spatial(
            { 0., 15., 0. },
            Quaternion3D(CCW, X, -90._deg) * Quaternion3D(CCW, Z, 180._deg )
        );        
        
        //  West box (so -Y)
        iq  = create_child<ImageQuad³>(
            AxBox2D(Vector2D(-15, -15), Vector2D(15, 15)), 
            "sdk/camera/WEST.JPG");
        iq->make_simple_spatial(
            { 0., -15., 0. },
            Quaternion3D(CCW, X, 90._deg) 
        );   
        
        //  Something in the NE corner
        Billboard³* bq  = create_child<Billboard³>(
            AxBox2D(Vector2D(-1, -1), Vector2D(1, 1)), 
            "sdk/camera/swirl.png"
        );
        bq->make_simple_spatial(
            { 14., 14., 0. }
        );

        Triangle³*   tri    = create_child<Triangle³>(TriData);
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
    return SimpleScene³::setup(ctx);
}
    
void CameraScene::init_info()
{
    auto w = writer<CameraScene>();
    w.description("Camera SDK Example Scene");
}

