////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

//#pragma once

#include <engine/Camera.hpp>
#include <engine/camera/CameraProxy.hpp>
#include <basic/DelayInit.hpp>
#include <basic/meta/Init.hpp>

namespace yq {
    namespace engine {

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

        CameraInfo::CameraInfo(std::string_view name, MetaObjectInfo& base, const std::source_location& sl) : 
            MetaObjectInfo(name, base, sl)
        {
            set_option(CAMERA);
            repo().all.push_back(this);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool CameraProxy::operator==(const CameraProxy&) const noexcept = default;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Camera::Camera()
        {
        }

        Camera::~Camera()
        {
        }

        CameraProxy     Camera::proxy(const CameraParams&p) const
        {
            return { id(), revision(), world2screen(p) };
        }

        void            Camera::set_name(const std::string& v)
        {
            m_name  = v;
        }
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        YQ_INVOKE(
            auto cam   = writer<Camera>();
            cam.property("name", &Camera::name).setter(&Camera::set_name);
            cam.abstract();
        )
    }
}

YQ_OBJECT_IMPLEMENT(yq::engine::Camera)
