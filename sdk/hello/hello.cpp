////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*

    This example is about demonstrating the use of the API to display a 
    simple triangle (in 2D mode) statically on the window.
    
    Note, it's heavily leveraged/inspired/taken from the Hello Triangle SDK example 
    located at https://vulkan-tutorial.com/Introduction
*/

//  Also it's about me developing the API in the first place .... :)

#include <tachyon/rendered/Triangle.hpp>
#include <yq/basic/DelayInit.hpp>
#include <yq/basic/Logging.hpp>

#include <yq/io/PluginLoader.hpp>

#include <0/meta/Meta.hpp>

#include <tachyon/Application.hpp>
#include <tachyon/Image.hpp>
#include <tachyon/Shader.hpp>
#include <tachyon/Texture.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/enum/FrontFace.hpp>
#include <tachyon/gpu/VqUtils.hpp>
#include <tachyon/PipelineBuilder.hpp>
#include <tachyon/Render3D.hpp>
#include <tachyon/Render3DWriter.hpp>
#include <tachyon/widget/Scene3DWidget.hpp>

#include <0/math/color/Colors.hpp>
#include <0/math/color/RGB.hpp>
#include <0/math/vector/Vector2.hpp>
#include <0/math/vector/Vector3.hxx>
#include <0/math/shape/shape_utils.hpp>
#include <0/math/shape/Triangle2.hpp>
#include <0/math/shape/Triangle3.hpp>
#include <iostream>
#include <chrono>
#include <yq/math/glm.hpp>  // temporary
#include <math.h>

using namespace yq;
using namespace yq::tachyon;

struct Vertex {
    glm::vec2   position;
    glm::vec3   color;
};

struct Warp {
    float   amt = 0;
};

const Vertex vertices[] = {
    {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
    {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
};

const auto  TriData   = TriangleData<ColorVertex2D>{ 
    { {0.5, 0.5}, color::Black },
    { {0.0,-0.5}, color::White },
    { {-0.5, 0.5}, color::Orange }
};

struct Vertex2 {
    glm::vec2   position;
    glm::vec2   uv;
};

const Vertex2 vertices2[] = {
    {{0.25, 0.25}, {0., 0.}},
    {{0.25, 0.75}, {0., 1.}},
    {{0.75, 0.25}, {1., 0.}},
    {{0.75, 0.75}, {1., 1.}}
};


using timepoint_t   = std::chrono::time_point<std::chrono::steady_clock>;

struct HelloTriangle : public Rendered {
    YQ_OBJECT_DECLARE(HelloTriangle, Rendered)
    
    struct MyUBO {
        //glm::mat4   model;
        //glm::mat4   view;
        //glm::mat4   proj;
        glm::vec4       dope;
    };
    
    UB1<MyUBO>          ubo;
    
    
    Warp                warp;
    
    static void initInfo()
    {
        static VBO<Vertex>  verts(vertices);
    
        auto w = writer<HelloTriangle>();
        {
            auto p = w.pipeline();
            p.shaders({ "sdk/hello/hello3.vert", "sdk/hello/hello2.frag" });
            p.front(FrontFace::Clockwise);
            p.push<Warp>(&HelloTriangle::warp);
            p.vertex(verts, DataActivity::COMMON)
                .attribute<glm::vec2>(&Vertex::position)
                .attribute<glm::vec3>(&Vertex::color)
            ;
            p.uniform(&HelloTriangle::ubo, DataActivity::DYNAMIC);
            //p.texture("sdk/hello/flowers-512.png");
            //p.ubo();
        }
    }
    
    HelloTriangle() 
    {
        ubo     = { { 1.0, 1.0, 1.0, 1.0 } };
    }
    
    ~HelloTriangle()
    {
    }
    
    void    update(double time)
    {
        uint32_t    sec = (int) time;
        bool        w = (sec & 1) != 0;
        warp.amt = (float)( 1.0 + 0.5*sin(time));
        set_wireframe( w ? Tristate::YES : Tristate::NO );
        ubo = { { 1.0+sin(time), 1.0+sin(2*time), 1.0+sin(3*time), 1.0 } };
    }
};


YQ_OBJECT_IMPLEMENT(HelloTriangle)

struct HelloQuad : public Rendered {
    YQ_OBJECT_DECLARE(HelloQuad, Rendered)

    Ref<const Texture>  tex;

    static void initInfo()
    {
        static VBO<Vertex2>  verts(vertices2);
        //static IB1<uint16_t> kIndices({ 0, 1, 2, 2, 3, 0 });

        auto w = writer<HelloQuad>();
        {
            auto p = w.pipeline();
            p.shaders({ "sdk/hello/quad.vert", "sdk/hello/quad.frag" });
            p.vertex(verts, DataActivity::COMMON)
                .attribute<glm::vec2>(&Vertex2::position)
                .attribute<glm::vec2>(&Vertex2::uv)
            ;
            p.topology(Topology::TriangleStrip);
            p.front(FrontFace::CounterClockwise);
            p.texture(&HelloQuad::tex, DataActivity::FIXED);
        }
    }
    
    HelloQuad()
    {
        Ref<const Image>    img = Image::load("sdk/hello/flowers-512.png");
        tex     = new Texture(img, ImageViewInfo(), SamplerInfo());
    }
};

YQ_OBJECT_IMPLEMENT(HelloQuad)

struct HelloScene : public Scene3DWidget {
    YQ_OBJECT_DECLARE(HelloScene, Scene3DWidget)
    
    Ref<HelloTriangle>      triangle;
    Ref<Triangle>           tri2;
    Ref<HelloQuad>          quad;
    timepoint_t             start;

    HelloScene()
    {
        start       = std::chrono::steady_clock::now();
        triangle    = new HelloTriangle;
        tri2        = new Triangle(TriData);
        tri2->set_position({0.,0.,0.1});
        quad        = new HelloQuad;
        
        add_thing(tri2);
        add_thing(triangle);
        add_thing(quad);
    }
    
    void    vulkan_(ViContext& v)
    {
        timepoint_t n   = std::chrono::steady_clock::now();
        std::chrono::duration<double>  diff    = start - n;
        tri2->set_heading( Degree(diff.count()) );
        triangle->update(diff.count());
        Scene3DWidget::vulkan_(v);
    }
};


YQ_OBJECT_IMPLEMENT(HelloScene)


int main(int argc, char* argv[])
{
    writer<HelloTriangle>();
    writer<HelloQuad>();

    AppCreateInfo        aci;
    aci.view.title        = "Hello WORLD!";
    aci.view.resizable    = true;
    aci.view.size         = { 1920, 1080 };
    aci.view.clear        = { 0.f, 0.1f, 0.2f, 1.f };
    
    Application app(argc, argv, aci);
    //load_plugin_dir("plugin");
    
    HelloTriangle::initInfo();
    HelloQuad::initInfo();
    
    app.finalize();
    app.add_viewer(new HelloScene);
    app.run();
    return 0;
}
