////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <basic/Object.hpp>
#include <basic/Ref.hpp>
#include <basic/UniqueID.hpp>
#include <math/shape/Rectangle2.hpp>
#include <glm/glm.hpp>
#include <meta/ObjectInfoWriter.hpp>

namespace yq {
    namespace tachyon {

        class Camera;
        
        class CameraInfo : public ObjectInfo {
        public:
            template <typename C> struct Writer;

            static const std::vector<const CameraInfo*>&    all();
            
            CameraInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());
        private:
            struct Repo;
            static Repo& repo();
        };


        /*! \brief Shows up on the screen
        
            If you want it to show up on the viewport, it needs to be renderable, and thus derived
            from this thing.
        */
        class Camera : public Object, public UniqueID, public RefCount {
            YQ_OBJECT_INFO(CameraInfo);
            YQ_OBJECT_DECLARE(Camera, Object)
        public:    
        
            struct Params;
        
            //! Returns the transform to go world -> screen space
            virtual glm::dmat4  world2screen(const Params&) const = 0;
        
            std::string_view    name() const { return m_name; }
            const std::string&  get_name() const { return m_name; }
            void                set_name(const std::string&);

        protected:
            Camera();
            ~Camera();
            
        private:
            std::string         m_name;
        };

        struct Camera::Params {
            Rectangle2D     screen;
        };

        template <typename C>
        class CameraInfo::Writer : public ObjectInfo::Writer<C> {
        public:
            Writer(CameraInfo* cameraInfo) : ObjectInfo::Writer<C>(cameraInfo)
            {
            }
            
            Writer(CameraInfo& cameraInfo) : Writer(&cameraInfo)
            {
            }
        };

    }
}
