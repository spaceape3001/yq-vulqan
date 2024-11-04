////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    This example will be about combinging ImGUI and the vulkan to have some controls
    as we play around with the camera.
*/

#include <yq/units.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/core/Logging.hpp>
#include <yq/color/colors.hpp>
#include <yq/color/RGB.hpp>
#include <yq/math/trigonometry.hpp>
#include <yq/shape/QuadrilateralData.hpp>
#include <yq/shape/TetrahedronData.hpp>
#include <yq/shape/Triangle2.hpp>
#include <yq/shape/Triangle3.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/shape/shape_utils.hpp>
#include <yq/text/match.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hxx>

#include <yq/tachyon/2D/Quadrilateral.hpp>
#include <yq/tachyon/2D/Triangle.hpp>
#include <yq/tachyon/3D/Tetrahedron.hpp>
#include <yq/tachyon/Application.hpp>
#include <yq/tachyon/Viewer.hpp>
#include <yq/tachyon/cameras/NullCamera.hpp>
#include <yq/tachyon/cameras/SpaceCamera.hpp>
#include <yq/tachyon/cameras/TargetCamera.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/Scene.hpp>
#include <yq/tachyon/WidgetInfoWriter.hpp>
#include <yq/tachyon/widgets/Scene3DWidget.hpp>

#include <chrono>

using namespace ImGui;
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

using timepoint_t   = std::chrono::time_point<std::chrono::steady_clock>;

const auto QuadData = QuadrilateralData<ColorVertex2D> {
    { {-1.0, 1.0}, color::Green },
    { {1.0, 1.0}, color::Blue },
    { {0.5, -1.0}, color::Yellow },
    { {-0.5, -1.0}, color::Red }
};

struct CameraScene3DWidget : public Scene3DWidget {
    YQ_OBJECT_DECLARE(CameraScene3DWidget, Scene3DWidget)

    std::vector<const CameraInfo*>      cam_infos;
    Map<std::string,Ref<Camera>,IgCase> cameras;

    timepoint_t             start;
    Ref<SpaceCamera>        cam;
    bool                    show_camera = true;
    bool                    slave_clock = true;
    bool                    show_control    = true;
    
    static void    init_info()
    {
        auto w = writer<CameraScene3DWidget>();
        w.imgui();
    }
    

    Camera*     add_camera(const CameraInfo* ci)
    {
        Ref<Camera> c   = new SpaceCamera; //static_cast<Camera*>(ci->create());
        if(!c){
            yError() << "Unable to create camera of type " << ci->name();
            return nullptr;
        }
        
        std::string     base(ci->name_stem());
        std::string     candidate   = base;
        for(unsigned int n=2; cameras.contains(candidate); ++n)
            candidate   = base + ':' + to_string(n);
        c->set_name(candidate);
        cameras[candidate]  = c;
        return c;
    }

    CameraScene3DWidget() 
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
        
        new SpaceCamera;
        
        Camera*     c   = add_camera(&meta<SpaceCamera>());
        assert(c);
        
        set_camera(c);
        
        cam     = static_cast<SpaceCamera*>(c);
        cam->set_position({-10, 0, -5.});
        cam->set_orientation(hpr((Radian) 0._deg, (Radian) 45._deg, (Radian) 0._deg));
        cam->set_near(.1);
        cam->set_far(20.);
        
        Ref<Triangle>   tri = new Triangle(TriData);
        tri->set_scaling(0.5);
        add_thing(tri);
        
        Ref<Tetrahedron>    dir     = new Tetrahedron(NorthData);
        dir->set_position({0., 5., 0. });
        add_thing(dir);

        dir     = new Tetrahedron(SouthData);
        dir->set_position({0., -5., 0. });
        add_thing(dir);
            
        dir     = new Tetrahedron(EastData);
        dir->set_position({5., 0., 0. });
        add_thing(dir);

        dir     = new Tetrahedron(WestData);
        dir->set_position({-5., 0., 0. });
        add_thing(dir);
        
        dir     = new Tetrahedron(TopData);
        dir->set_position({0., 0., 5. });
        add_thing(dir);
        
        dir     = new Tetrahedron(BottomData);
        dir->set_position({0., 0., -5. });
        add_thing(dir);
            
        Ref<Quadrilateral> quad = new Quadrilateral(QuadData);
        quad->set_scaling(0.5);
        quad->set_heading( (Radian) 45._deg );
        quad->set_position({ 0.5, 0.5, 0. });
        add_thing(quad);
    }

    void        vulkan_(ViContext& ctx) override
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

        Scene3DWidget::vulkan_(ctx);
    }
    
    void    imgui_(ViContext&) override
    {
        if(BeginMainMenuBar()){
            if(BeginMenu("Camera")){
                if(BeginMenu("Create")){
                    for(const CameraInfo* ci : cam_infos){
                        std::string txt(ci->name_stem());
                        if(MenuItem(txt.c_str())){
                            Camera*c    = add_camera(ci);
                            if(c){
                                set_camera(c);
                            }
                        }
                    }
                
                    EndMenu();
                }
                
                if(BeginMenu("Switch")){
                    for(auto& ci : cameras){
                        if(RadioButton(ci.first.c_str(), ci.second.ptr() == perspective.camera.ptr())){
                            set_camera(ci.second.ptr());
                        }
                    }
                
                    EndMenu();
                }
                Checkbox("Control", &show_control);
                #if 0
                Separator();
                if(MenuItem("Exit"))
                    cmd_close();
                #endif
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

YQ_OBJECT_IMPLEMENT(CameraScene3DWidget)

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.view.title        = "Cameras!";
    aci.view.resizable    = false;
    aci.view.size         = { 1920, 1080 };
    aci.view.clear        = { 0.1f, 0.1f, 0.2f, 1.f };
    aci.view.imgui        = true;
    
    Application app(argc, argv, aci);
    
    //load_plugin_dir("plugin");
    app.finalize();
    app.run(new CameraScene3DWidget);
    return 0;
}



