////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/light.hpp>

namespace yq::tachyon {

    class Light;
    
    /*! \brief Light Information
    
        Information for cameras.
    */
    class LightInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const LightInfo*>&    all();
        
        //! Standard constructor for the camera information
        LightInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the camera is assumed to be simple....
    */


    /*! \brief Shows up on the screen
    
        If you want it to show up on the viewport, it needs to be renderable, and thus derived
        from this thing.  
        
        \note We're limited to three dimensions here
    */
    class Light : public Tachyon {
        YQ_TACHYON_INFO(LightInfo);
        YQ_TACHYON_DATA(LightData)
        YQ_TACHYON_SNAP(LightSnap)
        YQ_TACHYON_DECLARE(Light, Tachyon)
    public:    
    
        /*
            We *MIGHT* want to divide up the camera into position, 
            lens, etc... or that's a later development on a dedicated
            camera.  (class DynamicLight, StandardLight, etc???)
        */
    
    
        //! Name of this camera's instance
        std::string_view    name() const { return m_name; }
        
        //! Getter for the property system
        const std::string&  get_name() const { return m_name; }
        
        //! Sets the camera's name
        void                set_name(const std::string&);

        static void init_info();

        LightID            id() const { return LightID(UniqueID::id()); }

    protected:
    
        void        snap(LightSnap&) const;
        //virtual void    receive(const post::PostCPtr&) override;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Light(const Param&p = {});
        
        //! Default destructor
        ~Light();
        
    private:
        std::string         m_name;
    };

}
