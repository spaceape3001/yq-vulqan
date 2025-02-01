////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraScene.hpp"

#include <yq/color/colors.hpp>
#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/TetrahedronData.hpp>
#include <yq/shape/TriangleData.hpp>

#include <ya/rendereds/Quadrilateral3.hpp>
#include <ya/rendereds/Triangle3.hpp>
#include <ya/rendereds/Tetrahedron3.hpp>

#include <yt/3D/Scene3InfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hxx>

using namespace yq;
using namespace yq::tachyon;

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

yq::tachyon::Execution  CameraScene::setup(const yq::tachyon::Context&ctx)
{
    if(!m_init){
        Triangle³*   tri    = create<Triangle³>(CHILD, TriData);
        tri->make_simple_spatial(ZERO, IDENTITY, Vector3D(ALL, 0.5));
        
        Rendered³*    dir     = create<Tetrahedron³>(CHILD, NorthData);
        dir -> make_simple_spatial({0., 5., 0. });

        dir     = create<Tetrahedron³>(CHILD, SouthData);
        dir -> make_simple_spatial({0., -5., 0. });
            
        dir     = create<Tetrahedron³>(CHILD, EastData);
        dir -> make_simple_spatial({5., 0., 0. });

        dir     = create<Tetrahedron³>(CHILD, WestData);
        dir -> make_simple_spatial({-5., 0., 0. });
        
        dir     = create<Tetrahedron³>(CHILD, TopData);
        dir -> make_simple_spatial({0., 0., 5. });
        
        dir     = create<Tetrahedron³>(CHILD, BottomData);
        dir -> make_simple_spatial({0., 0., -5. });
            
        Quadrilateral³* quad = create<Quadrilateral³>(CHILD, QuadData);
        quad->make_simple_spatial(
            { 0.5, 0.5, 0. },
            Quaternion3D(CCW, Z, (Radian) 45._deg ),
            Vector3D(ALL, 0.5)
        );
    }
    return SimpleScene³::setup(ctx);
}
    
void CameraScene::init_info()
{
    auto w = writer<CameraScene>();
    w.description("Camera Scene");
}

