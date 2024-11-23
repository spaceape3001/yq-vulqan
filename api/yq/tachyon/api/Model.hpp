////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/model.hpp>

namespace yq::tachyon {

    class Model;
    
    /*! \brief Model Information
    
        Information for cameras.
    */
    class ModelInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const ModelInfo*>&    all();
        
        //! Standard constructor for the camera information
        ModelInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
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
    class Model : public Tachyon {
        YQ_TACHYON_INFO(ModelInfo);
        YQ_TACHYON_DATA(ModelData)
        YQ_TACHYON_SNAP(ModelSnap)
        YQ_TACHYON_DECLARE(Model, Tachyon)
    public:    
    
        /*
            We *MIGHT* want to divide up the camera into position, 
            lens, etc... or that's a later development on a dedicated
            camera.  (class DynamicModel, StandardModel, etc???)
        */
    
    
        //! Name of this camera's instance
        std::string_view    name() const { return m_name; }
        
        //! Getter for the property system
        const std::string&  get_name() const { return m_name; }
        
        //! Sets the camera's name
        void                set_name(const std::string&);

        static void init_info();

        ModelID            id() const { return ModelID(UniqueID::id()); }

    protected:
    
        void        snap(ModelSnap&) const;
        //virtual void    receive(const post::PostCPtr&) override;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Model(const Param&p = {});
        
        //! Default destructor
        ~Model();
        
    private:
        std::string         m_name;
    };

}
