////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Camera3.hpp"
#include "Camera3Data.hpp"
#include "Camera3MetaWriter.hpp"
#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tachyon/command/camera/SetScreenCommand.hpp>
#include <yq/tachyon/api/dim/3DWriter.hxx>
#include <yq/meta/Init.hpp>
#include <yq/tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Camera³ID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Camera³Data)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Camera³Snap)

namespace yq::tachyon {
    Camera³Meta::Camera³Meta(std::string_view name, CameraMeta& base, const std::source_location& sl) :
        CameraMeta(name, base, sl)
    {
        set(Type::Camera³);
    }

    Camera³Meta::~Camera³Meta()
    {
    }

    /////////////////////////////////////////////////////////////////////////////

    Camera³Data::Camera³Data() = default;
    Camera³Data::~Camera³Data() = default;
    
    void Camera³Data::init_meta()
    {
        auto w = writer<Camera³Data>();
        w.description("Camera³ Frame Data");
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Camera³Snap::Camera³Snap() = default;
    Camera³Snap::~Camera³Snap() = default;
    
    void Camera³Snap::init_meta()
    {
        auto w = writer<Camera³Snap>();
        w.description("Camera³ Snapshot");
        w.property("view", READ_ONLY, &Camera³Snap::view);
        w.property("projection", READ_ONLY, &Camera³Snap::projection);
        w.property("screen", READ_ONLY, &Camera³Snap::screen);
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Camera³::Camera³(const Param& p) : Camera(p)
    {
        //  total hack (for now)
        m_screen.size.x = 1920;
        m_screen.size.y = 1080;
    }
    
    Camera³::~Camera³()
    {
    }
    

    void Camera³::finalize(Camera³Data&d) const
    {
        ③::finalize(d);
        Camera::finalize(d);
    }
    
    void Camera³::on_set_screen(const SetScreenCommand& cmd)
    {
        if(cmd.target() == id()){
            m_screen        = cmd.screen();
            mark();
        }
    }
    
    void Camera³::snap(Camera³Snap& sn) const
    {
        ③::snap(sn);
        Camera::snap(sn);
        sn.screen   = m_screen;
    }

    void Camera³::init_meta()
    {
        auto w = writer<Camera³>();
        ③::init_meta(w);
        w.description("Camera in 3D");
        w.slot(&Camera³::on_set_screen);
        w.abstract();
        w.alias("Camera3");
        
        auto wt = writer<Camera³ID>();
        wt.alias("Camera3ID");
        wt.description("3D Camera Identifier");
        wt.set(Meta::Flag::ID);
    }
}
