////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/typedef/kinetic.hpp>

namespace yq::tachyon {

    class Kinetic;
    
    /*! \brief Kinetic Information
    
        Information for cameras.
    */
    class KineticMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const KineticMeta*>&    all();
        
        //! Standard constructor for the camera information
        KineticMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
        
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
    class Kinetic : public Tachyon {
        YQ_TACHYON_META(KineticMeta);
        YQ_TACHYON_DATA(KineticData)
        YQ_TACHYON_SNAP(KineticSnap)
        YQ_TACHYON_DECLARE(Kinetic, Tachyon)
    public:    
    
        static constexpr const Type kType   = Type::Kinetic;

        /*
            We *MIGHT* want to divide up the camera into position, 
            lens, etc... or that's a later development on a dedicated
            camera.  (class DynamicKinetic, StandardKinetic, etc???)
        */
        /*
            PARAMETERS -- might need to move to a map?  Otherwise it's 
            structure referencing structure... 
        */
    
    
        //! Generic parameter structure
        //! Allows us to expand parameters w/o affecting *everybody*
        //struct Values;
    
        //! Returns the transform to go world -> screen space
        //virtual glm::dmat4  world2screen(const Values&) const = 0;
    
        static void init_meta();

        KineticID            id() const { return KineticID(UniqueID::id()); }

    protected:
    
        void        snap(KineticSnap&) const;
        void        finalize(KineticData&) const;
        
        
        //! Default constructor
        Kinetic(const Param&p = {});
        
        //! Default destructor
        virtual ~Kinetic();
        
    };
    
    /*! \brief Kinetic parameters
    */
    //struct Kinetic::Values {
        ////  Dimensions of the screen
        //Rectangle2D     screen;
    //};
}
YQ_TYPE_DECLARE(yq::tachyon::KineticID)
