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

namespace yq::tachyon {

    class Camera;
    
    /*! \brief Camera Information
    
        Information for cameras.
    */
    class CameraInfo : public ObjectInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const CameraInfo*>&    all();
        
        //! Standard constructor for the camera information
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
    
        //! Generic parameter structure
        //! Allows us to expand parameters w/o affecting *everybody*
        struct Params;
    
        //! Returns the transform to go world -> screen space
        virtual glm::dmat4  world2screen(const Params&) const = 0;
    
        //! Name of this camera's instance
        std::string_view    name() const { return m_name; }
        
        //! Getter for the property system
        const std::string&  get_name() const { return m_name; }
        
        //! Sets the camera's name
        void                set_name(const std::string&);

    protected:
    
        //! Default constructor
        Camera();
        
        //! Default destructor
        ~Camera();
        
    private:
        std::string         m_name;
    };

    /*! \brief Camera parameters
    */
    struct Camera::Params {
        //  Dimensions of the screen
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
