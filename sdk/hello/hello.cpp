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

#include <asset/Triangle.hpp>
#include <basic/DelayInit.hpp>
#include <basic/Logging.hpp>

#include <io/PluginLoader.hpp>

#include <meta/Meta.hpp>

#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/camera/NullCamera.hpp>
#include <tachyon/enum/FrontFace.hpp>
#include <tachyon/gpu/VqUtils.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <tachyon/gfx/PipelineBuilder.hpp>
#include <tachyon/scene/Scene.hpp>
#include <tachyon/scene/Scene3D.hpp>
#include <tachyon/scene/Render3D.hpp>
#include <tachyon/scene/Render3DWriter.hpp>

#include <math/color/Colors.hpp>
#include <math/color/RGB.hpp>
#include <math/vector/Vector2.hpp>
#include <math/vector/Vector3.hxx>
#include <math/shape/shape_utils.hpp>
#include <math/shape/Triangle2.hpp>
#include <math/shape/Triangle3.hpp>
#include <iostream>
#include <chrono>
#include <glm/glm.hpp>  // temporary
#include <math.h>

using namespace yq;
using namespace yq::asset;
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

using timepoint_t   = std::chrono::time_point<std::chrono::steady_clock>;

struct HelloTriangle : public Rendered {
    YQ_OBJECT_DECLARE(HelloTriangle, Rendered)
    
    struct MyUBO {
        glm::mat4   model;
        glm::mat4   view;
        glm::mat4   proj;
        glm::vec4   dope;
    };
    
    
    Warp                        warp;
    
    static void initInfo()
    {
        auto w = writer<HelloTriangle>();
        {
            auto p = w.pipeline();
            p.shaders({ "sdk/hello/hello3.vert", "sdk/hello/hello.frag" });
            p.front(FrontFace::Clockwise);
            p.push<Warp>(&HelloTriangle::warp);
            p.common_vertex(vertices)
                .attribute<glm::vec2>(&Vertex::position)
                .attribute<glm::vec3>(&Vertex::color)
            ;
            //p.ubo();
        }
    }
    
    HelloTriangle() 
    {
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
    }
};

YQ_INVOKE(
    [[maybe_unused]] auto ht   = writer<HelloTriangle>();
)

YQ_OBJECT_IMPLEMENT(HelloTriangle)


struct HelloScene : public Scene3D {
    YQ_OBJECT_DECLARE(HelloScene, Scene3D)
    
    Ref<HelloTriangle>      triangle;
    Ref<Triangle>           tri2;
    Ref<Camera>             camera;
    Ref<Scene>              scene;
    timepoint_t             start;

    HelloScene()
    {
        start   = std::chrono::steady_clock::now();
        scene       = new Scene;
        camera      = new NullCamera;
        set_camera(camera);
        set_scene(scene);
        triangle = new HelloTriangle;
        tri2        = new Triangle(TriData);
        tri2->set_position({0.,0.,0.1});
        scene->things.push_back(triangle);
        scene->things.push_back(tri2);
    }
    
    void    vulkan_(ViContext& v)
    {
        timepoint_t n   = std::chrono::steady_clock::now();
        std::chrono::duration<double>  diff    = start - n;
        tri2->set_heading( Degree(diff.count()) );
        triangle->update(diff.count());
        Scene3D::vulkan_(v);
    }
};


YQ_OBJECT_IMPLEMENT(HelloScene)


int main(int argc, char* argv[])
{
    AppCreateInfo        vi;
    
    Application app(argc, argv, vi);
    //load_plugin_dir("plugin");
    
    HelloTriangle::initInfo();
    
    app.finalize();
    
    ViewerCreateInfo      wi;
    wi.title        = "Hello WORLD!";
    wi.resizable    = true;
    wi.size         = { 1920, 1080 };
    wi.clear        = { 0.f, 0.1f, 0.2f, 1.f };

    Ref<Viewer> v = new Viewer(wi, new HelloScene);
    app.run(v.ptr());
    
    std::cout << "Hello World!\n";
    return 0;
}
