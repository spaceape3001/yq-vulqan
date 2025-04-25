////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SpaceCameraRemote.hpp"
#include <tachyon/api/Camera3.hpp>
#include <tachyon/api/Camera3Data.hpp>
#include <tachyon/api/Spatial3.hpp>
#include <tachyon/api/Spatial3Data.hpp>
#include <tachyon/api/Frame.hpp>
#include <ya/controls/Orientation3Control.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/logging.hpp>

#include <tachyon/proxy/POrientation3.hpp>
#include <tachyon/proxy/PPosition3.hpp>
#include <yq/util/Safety.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SpaceCameraRemote)

namespace yq::tachyon {
    SpaceCameraRemote::SpaceCameraRemote(TypedID tid)  : m_camera(tid)
    {
    }

    SpaceCameraRemote::~SpaceCameraRemote()
    {
    }

    Execution SpaceCameraRemote::setup(const Context&ctx)
    {
        if(!m_init){
            if(!m_camera)
                return ABORT;
            
            const Frame*    frame   = Frame::current();
            if(!frame)
                return WAIT;
         
            if(!m_spatial){
                const Camera³Snap*   sn  = frame->snap((Camera³ID) m_camera);
                if(!sn)
                    return WAIT;

                if(!sn->spatial)
                    return WAIT;


                Types   t   = frame->types(sn->spatial);
                if(!t)
                    return WAIT;

                if(!t(Type::Spatial³))
                    return ABORT;
                    
                m_spatial           = TypedID(sn->spatial.id, t);
                m_orientation       = create_child<Orientation³Control>(m_spatial);
            }
            
            m_init  = true;
        }
        
        return Widget::setup(ctx);
    }

    #if 0
        //  OLD CODE
        

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

    #endif

    void    SpaceCameraRemote::imgui(ViContext&u)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;

        PPosition³*pos        = frame->proxy<PPosition³>(m_spatial);
        if(!pos)
            return;

        POrientation³*ori     = frame->proxy<POrientation³>(m_spatial);
        if(!ori)
            return;
            
        if(!ImGui::Begin("Space Camera Remote"))
            return ;
            
        Vector3D        position    = pos->position();
        if(ImGui::InputDouble3("", &position))
            pos->position(SET, position);

        if(m_orientation)
            m_orientation->imgui(u);
        
        //Quaternion3D    orient      = ori->orientation();
        //if(ImGui::InputDouble4("Orientation", &orient))
            //ori->orientation(SET, orient);
        
        //if(ImGui::Button("+ roll"))
            //ori->orientation(ROTATE, ROLL, 10._deg);
        //if(ImGui::Button("- roll"))
            //ori->orientation(ROTATE, ROLL, -10._deg);

        //if(ImGui::Button("+ pitch"))
            //ori->orientation(ROTATE, PITCH, 10._deg);
        //if(ImGui::Button("- pitch"))
            //ori->orientation(ROTATE, PITCH, -10._deg);
        //if(ImGui::Button("+ yaw"))
            //ori->orientation(ROTATE, YAW, 10._deg);
        //if(ImGui::Button("- yaw"))
            //ori->orientation(ROTATE, YAW, -10._deg);
            
        ImGui::End();
    }


    void SpaceCameraRemote::init_info()
    {
        auto w = writer<SpaceCameraRemote>();
        w.description("Space Camera Remote");
    }
}
