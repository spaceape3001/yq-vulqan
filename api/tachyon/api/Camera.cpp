////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/CameraInfoWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

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
        set(Type::Camera);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Camera::Camera(const Param& p) : Tachyon(p)
    {
    }

    Camera::~Camera()
    {
    }

    void Camera::finalize(CameraData& d) const
    {
        Tachyon::finalize(d);
    }

    void Camera::snap(CameraSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Camera::init_info()
    {
        auto w   = writer<Camera>();
        w.abstract();
        w.description("A camera, a viewpoint");

        auto wt = writer<CameraID>();
        wt.description("Camera Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera)
YQ_TYPE_IMPLEMENT(yq::tachyon::CameraID)
