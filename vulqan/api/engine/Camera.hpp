////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/MetaObject.hpp>
#include <engine/preamble.hpp>
#include <math/Size2.hpp>

#include <glm/glm.hpp>

namespace yq {
    namespace engine {

        class Camera;
        
        class CameraInfo : public MetaObjectInfo {
        public:
            template <typename C> struct Writer;

            static const std::vector<const CameraInfo*>&    all();
            
            CameraInfo(std::string_view, MetaObjectInfo&, const std::source_location& sl = std::source_location::current());
        private:
            struct Repo;
            static Repo& repo();
        };

        struct CameraProxy;


        struct CameraParams {
            Size2D          screen{};
        };


        /*! \brief Shows up on the screen
        
            If you want it to show up on the viewport, it needs to be renderable, and thus derived
            from this thing.
        */
        class Camera : public MetaObject {
            YQ_OBJECT_INFO(CameraInfo);
            YQ_OBJECT_DECLARE(Camera, MetaObject)
        public:    
        
            //! Returns the transform to go world -> screen space
            virtual glm::dmat4  world2screen(const CameraParams&) const = 0;
        
            CameraProxy         proxy(const CameraParams&) const;
            const std::string&  name() const { return m_name; }
            void                set_name(const std::string&);

        protected:
            Camera();
            ~Camera();
            
        private:
            std::string         m_name;
        };
        
        template <typename C>
        class CameraInfo::Writer : public MetaObjectInfo::Writer<C> {
        public:
            Writer(CameraInfo* cameraInfo) : MetaObjectInfo::Writer<C>(cameraInfo)
            {
            }
            
            Writer(CameraInfo& cameraInfo) : Writer(&cameraInfo)
            {
            }
        };

    }
}
