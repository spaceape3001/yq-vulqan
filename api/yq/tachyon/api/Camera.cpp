////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/CameraMetaWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct CameraMeta::Repo {
        std::vector<const CameraMeta*> all;
    };
    
    CameraMeta::Repo& CameraMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const CameraMeta*>&    CameraMeta::all()
    {
        return repo().all;
    }

    CameraMeta::CameraMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
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
    
    void Camera::init_meta()
    {
        auto w   = writer<Camera>();
        w.abstract();
        w.description("A camera, a viewpoint");

        auto wt = writer<CameraID>();
        wt.description("Camera Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Camera>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera)
YQ_TYPE_IMPLEMENT(yq::tachyon::CameraID)
