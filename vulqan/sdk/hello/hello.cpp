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

#include <asset/Colors.hpp>
#include <asset/NullCamera.hpp>
#include <asset/Triangle.hpp>
#include <basic/DelayInit.hpp>
#include <basic/Logging.hpp>
#include <basic/PluginLoader.hpp>
#include <basic/meta/Meta.hpp>
#include <engine/Application.hpp>
#include <engine/Scene.hpp>
#include <engine/Shader.hpp>
#include <engine/Perspective.hpp>
#include <engine/Viewer.hpp>
#include <engine/render/PipelineBuilder.hpp>
#include <engine/render/Render3D.hpp>
#include <engine/render/RenderWriter.hpp>
#include <engine/vulqan/VqBuffer.hpp>
#include <engine/vulqan/VqCommand.hpp>
#include <engine/vulqan/VqUtils.hpp>
#include <engine/vulqan/VqPipeline.hpp>
#include <math/RGB.hpp>
#include <math/Vector2.hpp>
#include <math/shape_math.hpp>
#include <math/Triangle2.hpp>
#include <math/Triangle3.hpp>
#include <iostream>
#include <chrono>
#include <glm/glm.hpp>  // temporary
#include <math.h>

using namespace yq;
using namespace yq::asset;
using namespace yq::engine;

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

struct HelloTriangle : public engine::Rendered {
    YQ_OBJECT_DECLARE(HelloTriangle, engine::Rendered)
    
    struct MyUBO {
        glm::mat4   model;
        glm::mat4   view;
        glm::mat4   proj;
        glm::vec4   dope;
    };
    
    std::unique_ptr<VqPipeline> m_pipeline;
    VqBuffer                    m_vbo;
    Viewer*                     m_window                = nullptr;
    
    HelloTriangle(Viewer*w) : m_window(w)
    {
        ShaderCPtr   vert = Shader::load("examples/hello3.vert");
        ShaderCPtr   frag = Shader::load("examples/hello.frag");
        if(!vert)
            throw std::runtime_error("No vertex shader");
        if(!frag)
            throw std::runtime_error("No fragment shader");
            

        PipelineConfig      cfg;
        PipelineBuilder      build(cfg);
        build.shaders({ vert, frag });
        build.front(FrontFace::Clockwise);
        build.push<Warp>();
        
        build.vbo<Vertex>()
            .attribute<glm::vec2>(&Vertex::position)
            .attribute<glm::vec3>(&Vertex::color)
        ;
        build.ubo();
        
        m_pipeline    = std::make_unique<VqPipeline>(*w, cfg);
        
        m_vbo   = VqBuffer(*w, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, vertices);
    }
    
    ~HelloTriangle()
    {
        m_pipeline  = {};
        m_vbo       = {};
    }
    
    void    render(VkCommandBuffer cmdbuf, double time)
    {
        uint32_t    sec = (int) time;
        bool        w = (sec & 1) != 0;
        Warp    warp { (float)( 1.0 + 0.5*sin(time)) };

        VkBuffer vertexBuffers[] = {m_vbo};
        VkDeviceSize offsets[] = {0};
    
        VqCommand       cmd;
        cmd.pipeline    = w ? m_pipeline->wireframe() : m_pipeline->pipeline();
        cmd.layout      = m_pipeline->layout();
        cmd.push        = warp; // VqCommand::Push{ &warp, sizeof(warp), m_pipeline.shader_mask() };
        cmd.push_mask   = m_pipeline->shader_mask();
        cmd.vbo         = VqCommand::VBO{ vertexBuffers, offsets, 1 };
        cmd.draw        = VqCommand::Draw{ 3 };
        record_draw(cmdbuf, cmd);
    }
};

YQ_INVOKE(
    [[maybe_unused]] auto ht   = writer<HelloTriangle>();
)

YQ_OBJECT_IMPLEMENT(HelloTriangle)


struct HelloWin : public engine::Viewer {
    YQ_OBJECT_DECLARE(HelloWin, engine::Viewer)
    
    timepoint_t             start;
    Ref<HelloTriangle>      triangle;
    Ref<Triangle>      tri2;
    Scene                   scene;
    Perspective             view;

    HelloWin(const ViewerCreateInfo& wci) : Viewer(wci)
    {
        start   = std::chrono::steady_clock::now();
        triangle = new HelloTriangle(this);
        tri2        = new yq::asset::Triangle(TriData);
        tri2->set_position({0.,0.,0.1});
        scene.things.push_back(tri2);
        view.camera = new NullCamera;
    }
    
    ~HelloWin()
    {
        triangle    = nullptr;
    }
    
    void        draw_vulqan(VkCommandBuffer cmdbuf)
    {
        timepoint_t n   = std::chrono::steady_clock::now();
        std::chrono::duration<double>  diff    = start - n;
        tri2->set_heading( Degree(diff.count()) );
        triangle->render(cmdbuf, diff.count());
        render(cmdbuf, scene, view);
    }
};

YQ_OBJECT_IMPLEMENT(HelloWin)


int main(int argc, char* argv[])
{
    AppCreateInfo        vi;
    
    Application app(argc, argv, vi);
    //load_plugin_dir("plugin");
    app.finalize();
    
    ViewerCreateInfo      wi;
    wi.title        = "Hello WORLD!";
    wi.resizable    = true;
    wi.size         = { 1920, 1080 };
    wi.clear        = { 0.f, 0.1f, 0.2f, 1.f };

    Ref<HelloWin>   win = new HelloWin(wi);
    if(!win->good())
        return -1;
    
    app.run_window(win.ptr());
    
    std::cout << "Hello World!\n";
    return 0;
}
