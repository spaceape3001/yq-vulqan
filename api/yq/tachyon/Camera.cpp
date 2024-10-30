////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/Camera.hpp>
#include <yq/tachyon/CameraInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

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

    CameraInfo::CameraInfo(std::string_view name, ObjectInfo& base, const std::source_location& sl) : 
        ObjectInfo(name, base, sl)
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

    void            Camera::set_name(const std::string& v)
    {
        m_name  = v;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    YQ_INVOKE(
        auto cam   = writer<Camera>();
        cam.property("name", &Camera::get_name).setter(&Camera::set_name);
        cam.abstract();
    )
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Camera)
