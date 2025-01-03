////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/CameraBind.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/api/CameraInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    CameraBind::CameraBind(const Camera* v) : m_camera(v ? v->id() : CameraID{})
    {
    }

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

    PostAdvice    Camera::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const CameraBind* p = dynamic_cast<const CameraBind*>(&pp)){
            if(p->camera() != id())
                return REJECT;
        }
        return {};
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
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera)
