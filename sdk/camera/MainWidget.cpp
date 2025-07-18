////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MainWidget.hpp"
#include "CameraScene.hpp"

#include <tachyon/camera/SpaceCamera.hpp>
#include <tachyon/command/controller/ListenCommand.hpp>
#include <tachyon/command/io/SaveCommand.hpp>
#include <tachyon/command/ui/CloseCommand.hpp>
#include <tachyon/controller/Space3Controller.hpp>
#include <tachyon/widget/FrameInspector.hpp>
#include <tachyon/widget/SpaceCameraRemote.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/app/Viewer.hpp>
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/WidgetMetaWriter.hpp>
#include <yq/text/match.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/Tachyon.hxx>

using namespace yq;
using namespace yq::tachyon;

YQ_TACHYON_IMPLEMENT(MainWidget)

void MainWidget::init_meta()
{
    auto w = writer<MainWidget>();
    w.description("Camera SDK Example Main Widget");
    w.vulkan();
}


MainWidget::MainWidget()
{
    for(const CameraMeta* ci : CameraMeta::all()){
        if(!ci)
            continue;
        if(ci->is_abstract())
            continue;
        m_cameras.push_back(Cam{ .info=ci, .stem=std::string(ci->name_stem())});
    }
    
    std::stable_sort(m_cameras.begin(), m_cameras.end(), 
        [](const Cam& a, const Cam& b) 
        {
            return is_less_igCase(a.stem, b.stem);
        }
    );
}

MainWidget::~MainWidget()
{
}

void    MainWidget::imgui(ViContext&ctx) 
{
    if(!m_init)
        return ;

    
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("Camera")){
        
            #if 0
            //  FROM THE PREVIOUS INCARNATION -- TO BE REIMPLEMENTED (LATER)
                if(ImGui::BeginMenu("Create Camera")){
                    for(const CameraMeta* ci : cam_infos){
                        std::string txt(ci->name_stem());
                        if(MenuItem(txt.c_str())){
                            Camera*c    = add_camera(*ci);
                            if(c){
                                set_camera(c);
                            }
                        }
                    }
                
                    ImGui::EndMenu();
                }
                
                if(ImGui::BeginMenu("Switch Camera")){
                    for(auto& ci : cameras){
                        if(ImGui::RadioButton(ci.first.c_str(), ci.second.ptr() == perspective.camera.ptr())){
                            set_camera(ci.second.ptr());
                        }
                    }
                
                    ImGui::EndMenu();
                }

                if(BeginMenu("Create Shape")){
                    ImGui::EndMenu();
                }
            
            #endif
        
            bool    f;
            if(m_inspector){
                f = m_inspector->visible();
                if(ImGui::Checkbox("Frame Inspector", &f)){
                    if(f){
                        m_inspector -> cmd_show();
                    } else {
                        m_inspector -> cmd_hide();
                    }
                }
            }

            if(m_remote){
                f           = m_remote->visible();
                if(ImGui::Checkbox("Remote", &f)){
                    if(f){
                        m_remote -> cmd_show();
                    } else {
                        m_remote -> cmd_hide();
                    }
                }
            }

            ImGui::Separator();
            if(ImGui::MenuItem("Save")){
                Post::Header    hdr;
                hdr.source      = *this;
                hdr.target      = (StdThread) SIM;
                
                yInfo() << "Sending save command";
                
                send(new SaveCommand(hdr, std::filesystem::path("camera.tsx")), hdr.target);
            }

            ImGui::Separator();
            if(ImGui::MenuItem("Exit")){
                mail(new CloseCommand({.target=*this}));
            }
            
            ImGui::EndMenu();
        }
     
        ImGui::EndMainMenuBar();
    }

    
    Widget::imgui(ctx);
}

Execution    MainWidget::setup(const Context& ctx) 
{
    if(!m_init){
        const Frame*    curFrame    = Frame::current();
        if(!curFrame)
            return WAIT;

        if(!curFrame->contains(id()))
            return WAIT;

        if(!m_scene){
            CameraScene*    sc  = create_on<CameraScene>(SIM);
            m_scene             = *sc;
            set_scene(sc->id());
        }
        if(!m_camera){
            SpaceCamera* cam    = create_on<SpaceCamera>(SIM);
            cam->make_simple_spatial(
                ZERO, IDENTITY, ONE
                //Vector3D(-10, 0, -5.),
                //Quaternion3D(HPR, (Radian) 0._deg, (Radian) 180._deg, (Radian) 0._deg)
            );
            cam->set_near(.1);
            cam->set_far(60.);
            m_camera    = *cam;
            set_camera(cam->id());
        }

        if(!curFrame->contains(m_scene))
            return WAIT;
        if(!curFrame->contains(m_camera))
            return WAIT;

        if(!m_controller)
            m_controller    = create_on<Space³Controller>(APP, m_camera);
        if(!m_inspector){
            // temporary disable
            //m_inspector     = create_child<FrameInspector>();
            //m_inspector -> cmd_hide();
        }
        if(!m_remote)
            m_remote        = create_child<SpaceCameraRemote>(m_camera);

        if(!curFrame->contains(m_controller))
            return WAIT;
            
        TachyonID    vid    = viewer();
        if(!curFrame->contains(vid))
            return WAIT;
        
        send(new ListenCommand({.target=m_controller}, TypedID(vid, Type::Viewer)));
        m_init = true;
    }
    return Widget::setup(ctx);
}


