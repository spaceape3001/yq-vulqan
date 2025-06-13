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

//  DEFINE THIS TO GET THE FRAME INSPECTOR
// #define WANT_FRAME_INSPECTOR

#include "types.hpp"

#include <yq/core/DelayInit.hpp>
#include <yq/core/Logging.hpp>
#include <yq/color/colors.hpp>
#include <yq/color/RGB.hpp>
#include <yq/meta/Meta.hpp>
//#include <yq/post/boxes/LoggerBox.hpp>
#include <yq/process/PluginLoader.hpp>
#include <yq/shape/shape_utils.hpp>
#include <yq/shape/Triangle2.hpp>
#include <yq/shape/Triangle3.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/text/match.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hxx>

#include <tachyon/application.hpp>
#include <tachyon/buffer.hpp>
#include <tachyon/rendered.hpp>
#include <tachyon/shader.hpp>
#include <tachyon/texture.hpp>
#include <tachyon/viewer.hpp>
#include <tachyon/widget.hpp>

#include <tachyon/command/orientation/SetOrientation3Command.hpp>
#include <tachyon/rendered/Triangle3.hpp>
#include <tachyon/api/Spatial3.hpp>
#include <tachyon/scene/SimpleScene.hpp>
#include <tachyon/api/Scene3InfoWriter.hpp>
#include <tachyon/api/WidgetInfoWriter.hpp>
#include <tachyon/widget/SceneWidget.hpp>
#include <tachyon/utility/LoggerBox.hpp>

#ifdef WANT_FRAME_INSPECTOR
#include <tachyon/widget/FrameInspector.hpp>
#endif

#include <iostream>
#include <math.h>

using namespace yq;
using namespace yq::tachyon;

TachyonID       gLogger;


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


const Vertex2 vertices2[] = {
    {{0.25, 0.25}, {0., 0.}},
    {{0.25, 0.75}, {0., 1.}},
    {{0.75, 0.25}, {1., 0.}},
    {{0.75, 0.75}, {1., 1.}}
};


class HelloTriangle : public Rendered {
    YQ_TACHYON_DECLARE(HelloTriangle, Rendered)
public:
    
    struct MyUBO {
        //glm::mat4   model;
        //glm::mat4   view;
        //glm::mat4   proj;
        glm::vec4       dope;
    };
    
    UB1<MyUBO>          ubo;
    
    
    Warp                warp;
    
    static void init_info()
    {
        static VBO<Vertex>  verts(vertices);
    
        auto w = writer<HelloTriangle>();
        w.description("Hello SDK Example Rendered");
        {
            auto& p = w.pipeline();
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
    
    HelloTriangle() : Rendered({})
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


YQ_TACHYON_IMPLEMENT(HelloTriangle)

class HelloQuad : public Rendered {
    YQ_TACHYON_DECLARE(HelloQuad, Rendered)
public:

    Ref<const Texture>  tex;

    static void init_info()
    {
        static VBO<Vertex2>  verts(vertices2);
        //static IB1<uint16_t> kIndices({ 0, 1, 2, 2, 3, 0 });

        auto w = writer<HelloQuad>();
        w.description("Hello SDK Example Quad");

        {
            auto& p = w.pipeline();
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
    
    HelloQuad() : Rendered({})
    {
        tex     = Texture::load("sdk/hello/flowers-512.png");
    }
};

YQ_TACHYON_IMPLEMENT(HelloQuad)

struct HelloScene : public SimpleScene {
    YQ_TACHYON_DECLARE(HelloScene, SimpleScene)
public:

    Ref<HelloTriangle>      triangle;
    Ref<Triangle³>          tri2;
    Ref<HelloQuad>          quad;
    timepoint_t             start;
    TypedID                 triSpatialID;

    HelloScene() 
    {
        start           = std::chrono::steady_clock::now();
        triangle        = create_child<HelloTriangle>();
        
        Triangle³::Param p;
        p.position      = {0.,0.,0.1};
        tri2            = create_child<Triangle³>(TriData, p);
        triSpatialID    = tri2 -> spatial();
        quad            = create_child<HelloQuad>();
        
        //add_thing(tri2);
        //add_thing(triangle);
        //add_thing(quad);
    }
    
    Execution tick(const Context& ctx)
    {
        SimpleScene::tick(ctx);
        timepoint_t n   = std::chrono::steady_clock::now();
        std::chrono::duration<double>  diff    = start - n;
        send(new SetOrientation³Command({.target=triSpatialID}, HPR, Degree(diff.count()), ZERO, ZERO), triSpatialID);
        triangle->update(diff.count());
        return {};
    }

    static void init_info()
    {
        auto w = writer<HelloScene>();
        w.description("Hello SDK Example Scene");
    }
};

YQ_TACHYON_IMPLEMENT(HelloScene)

class HelloWidget : public SceneWidget {
    YQ_TACHYON_DECLARE(HelloWidget, SceneWidget)
public:

    HelloWidget()
    {
    }
    
    Execution setup(const Context&) override
    {
        return {};
    }
    
    static void init_info()
    {
        auto w = writer<HelloWidget>();
        w.description("Hello SDK Example Widget");
    }
};

YQ_TACHYON_IMPLEMENT(HelloWidget)


//using LoggerBoxUPtr     = std::unique_ptr<post::LoggerBox>;

int main(int argc, char* argv[])
{
    #if 0
    bool    posts = false;
    
    for(int n=1;n<argc;++n){
        if(is_similar(argv[n], "--posts"))
            posts   = true;
        if(is_similar(argv[n], "--post"))
            posts   = true;
    }
    #endif

    AppCreateInfo        aci;
    
    aci.thread.sim      = true;
    
    aci.view.title      = "Hello WORLD!";
    aci.view.resizable  = true;
    aci.view.size       = { 1920, 1080 };
    aci.view.clear      = { 0.f, 0.1f, 0.2f, 1.f };
    aci.vulkan.transfer   = OPTIONAL;

    #ifdef WANT_FRAME_INSPECTOR
    aci.view.imgui      = true;
    #endif
    
    Application app(argc, argv, aci);
    //load_plugin_dir("plugin");
    
    #if 0
    LoggerBoxUPtr       postLogging;
    if(posts){
        post::LoggerBox::Param  cfg;
        cfg.global  = true;
        postLogging = std::make_unique<post::LoggerBox>(cfg);
    }
    #endif

    app.start();
    
    HelloScene*     sc  = Tachyon::create_on<HelloScene>(SIM);
    HelloWidget*    w   = Tachyon::create<HelloWidget>();
    w -> set_scene(sc->id());
    
    #ifdef WANT_FRAME_INSPECTOR
    w -> create_child<FrameInspector>();
    #endif
    
    //LoggerBox*  lb  = Tachyon::create<LoggerBox>();
    //gLogger = lb->id();
    //lb->unsafe_snoop(w);

    app.run(w);
    return 0;
}
