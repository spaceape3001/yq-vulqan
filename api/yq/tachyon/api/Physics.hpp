////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/physics.hpp>

namespace yq::tachyon {

    class Physics;
    
    /*! \brief Physics Information
    
        Information for physics.
    */
    class PhysicsMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const PhysicsMeta*>&    all();
        
        //! Standard constructor for the camera information
        PhysicsMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
        
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the camera is assumed to be simple....
    */


    /*! \brief Rules of the road for a kinetic
    
        This is the general rules of the road for a kinetic object; gravity, collision, terrain effects,
        collision, etc will be stored/managed here.  It'll be ONE physics object to a domain/kinetic.  
        Now, physics objects can be chained together (like kinetics)
        
        Note, physics will be expected to have delegates/functions, for the various rules (like 
        gravity or collision or coordinate mapping), and these delegates will be accessible from 
        the snap).
        
        \note We *might* have a data manager for the actual environment data, that'll get requests and
        what not.  It'll be this physics tachyon that's required to package it up for everybody else to use.
    */
    class Physics : public Tachyon {
        YQ_TACHYON_META(PhysicsMeta);
        YQ_TACHYON_DATA(PhysicsData)
        YQ_TACHYON_SNAP(PhysicsSnap)
        YQ_TACHYON_DECLARE(Physics, Tachyon)
    public:    
    
        /*
            PARAMETERS -- might need to move to a map?  Otherwise it's 
            structure referencing structure... 
        */
    
        /*
            2026 MAY 25 -- moving toward a physics being a *single* type of
            thing (ie, collision KD tree or spring force)
        */
    
    
        //! Generic parameter structure
        //! Allows us to expand parameters w/o affecting *everybody*
        //struct Values;
    
        static void init_meta();

        PhysicsID            id() const { return PhysicsID(UniqueID::id()); }

    protected:
    
        void        snap(PhysicsSnap&) const;
        void        finalize(PhysicsData&) const;
        
        //! Default constructor
        Physics(const Param&p = {});
        
        //! Default destructor
        virtual ~Physics();
        
    };
}
YQ_TYPE_DECLARE(yq::tachyon::PhysicsID)
