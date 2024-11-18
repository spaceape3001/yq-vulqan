////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/camera/Camera.hpp>
#include <yq/tachyon/camera/CameraBind.hpp>
#include <yq/tachyon/camera/CameraInfoWriter.hpp>

namespace yq::tachyon {

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct CameraInfo::Repo {
        std::vector<const CameraInfo*> all;
    };
    
    CameraInfo::Repo& CameraInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const CameraInfo*>&    CameraInfo::all()
    {
        return repo().all;
    }

    CameraInfo::CameraInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Flag::CAMERA);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Camera::Camera()
    {
    }

    Camera::~Camera()
    {
    }

    void Camera::snap(CameraData& data) const
    {
        Tachyon::snap(data);
    }

    void            Camera::set_name(const std::string& v)
    {
        m_name  = v;
    }

    void    Camera::receive(const post::PostCPtr&pp)
    {
        if(!pp)
            return;
        if(const CameraBind* p = dynamic_cast<const CameraBind*>(pp.ptr())){
            if(p->camera() != this)
                return ;
            if(!in_replay())
                forward(pp);
        } else if(!in_replay()){   
            forward(pp);
        }
        Tachyon::receive(pp);
    }

    void Camera::tick()
    {
        replay(ALL);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Camera::init_info()
    {
        auto w   = writer<Camera>();
        w.property("name", &Camera::get_name).setter(&Camera::set_name);
        w.abstract();
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Camera)
