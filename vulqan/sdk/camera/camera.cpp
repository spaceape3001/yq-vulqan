////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    This example will be about combinging ImGUI and the vulkan to have some controls
    as we play around with the camera.
*/

#include <asset/Colors.hpp>
#include <asset/NullCamera.hpp>
#include <asset/SpaceCamera.hpp>
#include <asset/TargetCamera.hpp>
#include <asset/Tetrahedron.hpp>
#include <asset/Triangle.hpp>
#include <asset/Quadrilateral.hpp>

#include <basic/DelayInit.hpp>
#include <basic/TextUtils.hpp>
#include <engine/Application.hpp>
#include <engine/Scene.hpp>
#include <engine/Perspective.hpp>
#include <engine/Viewer.hpp>

#include <math/RGB.hpp>
#include <math/Vector2.hpp>
#include <math/shape_math.hpp>
#include <math/Units.hpp>
#include <math/trig.hpp>
#include <math/QuadrilateralData.hpp>
#include <math/TetrahedronData.hpp>
#include <math/Triangle2.hpp>
#include <math/Triangle3.hpp>
#include <MyImGui.hpp>
#include <chrono>

using namespace ImGui;
using namespace yq;
using namespace yq::asset;
using namespace yq::engine;

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

using timepoint_t   = std::chrono::time_point<std::chrono::steady_clock>;

const auto QuadData = QuadrilateralData<ColorVertex2D> {
    { {-1.0, 1.0}, color::Green },
    { {1.0, 1.0}, color::Blue },
    { {0.5, -1.0}, color::Yellow },
    { {-0.5, -1.0}, color::Red }
};

struct CameraWin : public engine::Viewer {
    YQ_OBJECT_DECLARE(CameraWin, engine::Viewer)

    std::vector<const CameraInfo*>      cam_infos;
    Map<std::string,Ref<Camera>,IgCase> cameras;

    timepoint_t             start;
    Ref<SpaceCamera>        cam;
    Scene                   scene;
    Perspective             view;
    bool                    show_camera = true;
    bool                    slave_clock = true;
    bool                    show_control    = true;

    Camera*     add_camera(const CameraInfo* ci)
    {
        Ref<Camera> c   = static_cast<Camera*>(ci->create());
        if(!c)
            return nullptr;
        
        std::string     base(ci->name_stem());
        std::string     candidate   = base;
        for(unsigned int n=2; cameras.contains(candidate); ++n)
            candidate   = base + ':' + to_string(n);
        c->set_name(candidate);
        cameras[candidate]  = c;
        return c;
    }

    CameraWin(const ViewerCreateInfo& wci) : Viewer(wci)
    {
        start   = std::chrono::steady_clock::now();
        
        for(const CameraInfo* i : CameraInfo::all()){
            if(i->is_abstract())
                continue;
            cam_infos.push_back(i);
        }
        
        std::sort(cam_infos.begin(), cam_infos.end(), 
            [](const CameraInfo* a, const CameraInfo* b)
            {
                return is_less_igCase(a->name_stem(), b->name_stem());
            }
        );
        
        Camera*     c   = add_camera(&meta<SpaceCamera>());
        
        view.camera = c;
        
        cam     = static_cast<SpaceCamera*>(c);
        cam->set_position({-10, 0, -5.});
        cam->set_orientation(hpr((Radian) 0._deg, (Radian) 45._deg, (Radian) 0._deg));
        cam->set_near(.1);
        cam->set_far(20.);
        
        Ref<Triangle>   tri = new Triangle(TriData);
        tri->set_scaling(0.5);
        scene.things.push_back(tri);
        
        Ref<Tetrahedron>    dir     = new Tetrahedron(NorthData);
        dir->set_position({0., 5., 0. });
        scene.things.push_back(dir);

        dir     = new Tetrahedron(SouthData);
        dir->set_position({0., -5., 0. });
        scene.things.push_back(dir);
            
        dir     = new Tetrahedron(EastData);
        dir->set_position({5., 0., 0. });
        scene.things.push_back(dir);

        dir     = new Tetrahedron(WestData);
        dir->set_position({-5., 0., 0. });
        scene.things.push_back(dir);
        
        dir     = new Tetrahedron(TopData);
        dir->set_position({0., 0., 5. });
        scene.things.push_back(dir);
        
        dir     = new Tetrahedron(BottomData);
        dir->set_position({0., 0., -5. });
        scene.things.push_back(dir);
            
        Ref<Quadrilateral> quad = new Quadrilateral(QuadData);
        quad->set_scaling(0.5);
        quad->set_heading( (Radian) 45._deg );
        quad->set_position({ 0.5, 0.5, 0. });
        scene.things.push_back(quad);
    }

    void        draw_vulqan(VkCommandBuffer cmdbuf) override
    {
        
        #if 0
        if(slave_clock){
            timepoint_t n   = std::chrono::steady_clock::now();
            std::chrono::duration<double>  diff    = start - n;
        
            Degree      angle{ diff.count() };
            
            auto ca     = cos((Radian) angle);
            auto sa     = sin((Radian) angle);
            Vector3D    p2{ 10. * ca, 0., 10 * sa };
            
            cam->set_position(p2);
            cam->set_orientation(rotor_y((Radian) -angle));
        }
        #endif

        render(cmdbuf, scene, view);
        //Window::draw_vulqan(cmdbuf);
    }
    
    void    draw_imgui() override
    {
        if(BeginMainMenuBar()){
            if(BeginMenu("Camera")){
                if(BeginMenu("Create")){
                    for(const CameraInfo* ci : cam_infos){
                        std::string txt(ci->name_stem());
                        if(MenuItem(txt.c_str())){
                            Camera*c    = add_camera(ci);
                            if(c){
                                view.camera = c;
                            }
                        }
                    }
                
                    EndMenu();
                }
                
                if(BeginMenu("Switch")){
                    for(auto& ci : cameras){
                        if(RadioButton(ci.first.c_str(), ci.second.ptr() == view.camera.ptr())){
                            view.camera = ci.second.ptr();
                        }
                    }
                
                    EndMenu();
                }
                Checkbox("Control", &show_control);
                Separator();
                if(MenuItem("Exit"))
                    close();
                EndMenu();
            }
            if(BeginMenu("Shape")){
                if(BeginMenu("Create")){
                    EndMenu();
                }
                EndMenu();
            }
            EndMainMenuBar();
        }
    
        if(show_control){
            if(BeginChild("Camera")){
            #if 1
                bool    changed = false;
            
                ToggleButton("motion", &slave_clock);
            
                Vector3D        pos = cam->position();
                if(InputDouble3("position", &pos))
                    cam->set_position(pos);
                Quaternion3D    orient  = cam->orientation();
                if(Button("+ roll")){
                    orient  = rotor_x((Radian)10._deg) * orient;
                    changed = true;
                }
                if(Button("- roll")){
                    orient  = rotor_x((Radian) -10._deg) * orient;
                    changed = true;
                }
                if(Button("+ pitch")){
                    orient  = rotor_y((Radian)10._deg) * orient;
                    changed = true;
                }
                if(Button("- pitch")){
                    orient  = rotor_y((Radian) -10._deg) * orient;
                    changed = true;
                }
                if(Button("+ yaw")){
                    orient  = rotor_z((Radian)10._deg) * orient;
                    changed = true;
                }
                if(Button("- yaw")){
                    orient  = rotor_z((Radian) -10._deg) * orient;
                    changed = true;
                }

                if(InputDouble4("orientation", &orient) || changed)
                    cam->set_orientation( ~orient);
                
            
            
                double          n   = cam->near();
                if(InputDouble("Near", &n))
                    cam->set_near(n);
                double          f   = cam->far();
                if(InputDouble("Far", &f))
                    cam->set_far(f);
                Degree          fov = cam->fov();
                if(InputDouble("FOV", &fov, 0.1_deg))
                    cam->set_fov(fov);
            
                Vector3D    scale   = cam->scale();
                if(InputDouble3("Scale", &scale))
                    cam->set_scale(scale);
            #endif
                EndChild();
            }
        }
    }
    
};

YQ_OBJECT_IMPLEMENT(CameraWin)

int main(int argc, char* argv[])
{
    AppCreateInfo        vi;
    
    Application app(argc, argv, vi);
    //load_plugin_dir("plugin");
    app.finalize();
    
    ViewerCreateInfo      wi;
    wi.title        = "Cameras!";
    wi.resizable    = false;
    wi.size         = { 1920, 1080 };
    wi.clear        = { 0.1f, 0.1f, 0.2f, 1.f };
    wi.imgui        = true;

    Ref<CameraWin>   win = new CameraWin(wi);
    if(!win->good())
        return -1;
    
    app.run_window(win.ptr());
    return 0;
}



