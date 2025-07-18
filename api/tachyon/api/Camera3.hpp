////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/3D.hpp>
#include <tachyon/api/Camera.hpp>
#include <tachyon/typedef/camera3.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    
    class SetScreenCommand;
    class SpatialCommand;

    class Camera³Meta : public CameraMeta {
    public:
    
        template <typename> class Writer;
        
        Camera³Meta(std::string_view, CameraMeta&, const std::source_location& sl = std::source_location::current());
    protected:
        ~Camera³Meta();
    };
    
    class Camera³ : public Camera, public ③ {
        YQ_TACHYON_META(Camera³Meta)
        YQ_TACHYON_SNAP(Camera³Snap)
        YQ_TACHYON_DATA(Camera³Data)
        YQ_TACHYON_DECLARE(Camera³, Camera)
    public:
    
        struct Param : public Camera::Param {
            // setting *ANY* of these creates a simple spatial (3D)
        
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
            
            Param(){}
        };
    
        static void init_meta();
    
        Camera³ID id() const { return Camera³ID(UniqueID::id()); }

        using Camera::mark;
    
    protected:
        Camera³(const Param&);
        virtual ~Camera³();
        
        void finalize(Camera³Data&) const;
        void snap(Camera³Snap&) const;
        
        //  TODO... make this clever with multiple clients?
        Rectangle2D     m_screen;

        using Tachyon::mail;
        using Tachyon::send;
        using Camera::id;
        
    private:
        void    on_set_screen(const SetScreenCommand&);
    };
}

YQ_TYPE_DECLARE(yq::tachyon::Camera³ID)

