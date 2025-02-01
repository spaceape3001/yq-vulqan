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

#include <yt/application.hpp>
#include <yt/controller.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/scene/Scene.hpp>
#include <yt/viewer.hpp>
#include <yt/widget.hpp>
#include <ya/cameras/NullCamera.hpp>
#include <ya/cameras/SpaceCamera.hpp>
#include <ya/cameras/TargetCamera.hpp>
//#include <ya/commands/CameraPitchCommand.hpp>
#include <ya/events/KeyPressEvent.hpp>
#include <ya/rendereds/Quadrilateral3.hpp>
#include <ya/rendereds/Triangle3.hpp>
#include <ya/rendereds/Tetrahedron3.hpp>
#include <ya/scenes/SimpleScene3.hpp>
#include <ya/utils/LoggerBox.hpp>
#include <ya/widgets/Scene3DWidget.hpp>
#include <ya/widgets/FrameInspector.hpp>

#include <chrono>

using namespace ImGui;
using namespace yq;
using namespace yq::tachyon;

using timepoint_t   = std::chrono::time_point<std::chrono::steady_clock>;


TachyonID       gLogger;



struct CameraScene3DWidget : public Scene³Widget {
    YQ_TACHYON_DECLARE(CameraScene3DWidget, Scene³Widget)

    std::vector<const CameraInfo*>      cam_infos;
    Map<std::string,Ref<Camera>,IgCase> cameras;

    timepoint_t             m_start;
    SpaceCamera*            m_cam = nullptr;
    bool                    m_show_camera = true;
    bool                    m_slave_clock = true;
    bool                    m_show_control    = true;
    bool                    m_init  = false;
    CameraScene*            m_scene   = nullptr;
    FrameInspector*         m_inspector = nullptr;
    
    
    static void    init_info()
    {
        auto w = writer<CameraScene3DWidget>();
        w.imgui();
    }
    

    Camera*     add_camera(const CameraInfo& ci)
    {
        Camera* c   = create<Camera>(ci);
        if(!c){
            yError() << "Unable to create camera of type " << ci.name();
            return nullptr;
        }
        
        std::string     base(ci.name_stem());
        std::string     candidate   = base;
        for(unsigned int n=2; cameras.contains(candidate); ++n)
            candidate   = base + ':' + to_string(n);
        //c->set_name(candidate);
        cameras[candidate]  = c;
        return c;
    }

    CameraScene3DWidget(CameraScene* sc)  : scene(sc)
    {
        setup();
    }
    
    void    setup(const Context& ctx) override
    {
    }
    
    void setup() 
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
        
        //new SpaceCamera;
        
        Camera*     c   = add_camera(meta<SpaceCamera>());
        assert(c);
        
        set_camera(c);
        
        
        
        cam     = static_cast<SpaceCamera*>(c);
        cam->make_simple_spatial(
            Vector3D(-10, 0, -5.),
            Quaternion3D(HPR, (Radian) 0._deg, (Radian) 180._deg, (Radian) 0._deg)
        );
        cam->set_near(.1);
        cam->set_far(20.);
        
        Triangle³*   tri = scene->create<Triangle³>(CHILD, TriData);
        tri->make_simple_spatial(ZERO, IDENTITY, Vector3D(ALL, 0.5));
        //tri->set_scaling(0.5);
        add_thing(tri);
        
        Tetrahedron³*    dir     = scene->create<Tetrahedron³>(CHILD, NorthData);
        dir -> make_simple_spatial({0., 5., 0. });
        add_thing(dir);

        dir     = scene->create<Tetrahedron³>(CHILD, SouthData);
        dir -> make_simple_spatial({0., -5., 0. });
        add_thing(dir);
            
        dir     = scene->create<Tetrahedron³>(CHILD, EastData);
        dir -> make_simple_spatial({5., 0., 0. });
        add_thing(dir);

        dir     = scene->create<Tetrahedron³>(CHILD, WestData);
        dir -> make_simple_spatial({-5., 0., 0. });
        add_thing(dir);
        
        dir     = scene->create<Tetrahedron³>(CHILD, TopData);
        dir -> make_simple_spatial({0., 0., 5. });
        add_thing(dir);
        
        dir     = scene->create<Tetrahedron³>(CHILD, BottomData);
        dir -> make_simple_spatial({0., 0., -5. });
        add_thing(dir);
            
        Quadrilateral³* quad = scene->create<Quadrilateral³>(CHILD, QuadData);
        quad->make_simple_spatial(
            { 0.5, 0.5, 0. },
            Quaternion3D(CCW, Z, (Radian) 45._deg ),
            Vector3D(ALL, 0.5)
        );
        add_thing(quad);
        
        CameraController*cc = create<CameraController>(cam);
        cc->cmd_listen(id());
        cc->cmd_control(gLogger);
    }
    
    Execution        tick(Context&) override
    {
        return {};
    }

    void        vulkan(ViContext& ctx) override
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

        Scene3DWidget0::vulkan(ctx);
    }
    
    void    imgui(ViContext&) override
    {
        if(BeginMainMenuBar()){
            if(BeginMenu("Camera")){
                if(BeginMenu("Create")){
                    for(const CameraInfo* ci : cam_infos){
                        std::string txt(ci->name_stem());
                        if(MenuItem(txt.c_str())){
                            Camera*c    = add_camera(*ci);
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
                
                if(MenuItem("Frame Inspector")){
                    create<FrameInspector>(CHILD);
                }
                
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

YQ_TACHYON_IMPLEMENT(CameraScene3DWidget)

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
    
    CameraScene* sc  = Tachyon::create<CameraScene>();
    Widget*     w   = Widget::create<CameraScene3DWidget>(sc);
    LoggerBox*  lb  = Tachyon::create<LoggerBox>();
    gLogger         = lb->id();
    //lb->unsafe_snoop(w);
    app.run(w);
    return 0;
}



