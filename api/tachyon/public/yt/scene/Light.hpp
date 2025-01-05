////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/typedef/light.hpp>

namespace yq::tachyon {

    class Light;
    
    /*! \brief Light Information
    
        Information for lights.
    */
    class LightInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all light informations
        static const std::vector<const LightInfo*>&    all();
        
        //! Standard constructor for the camera information
        LightInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the light is assumed to be simple....
    */

    /*! \brief A light
    */
    class Light : public Tachyon {
        YQ_TACHYON_INFO(LightInfo);
        YQ_TACHYON_DATA(LightData)
        YQ_TACHYON_SNAP(LightSnap)
        YQ_TACHYON_DECLARE(Light, Tachyon)
    public:    
    
        static void init_info();

        LightID            id() const { return LightID(UniqueID::id()); }

    protected:
    
        void        snap(LightSnap&) const;
        void        finalize(LightData&) const;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Light(const Param&p = {});
        
        //! Default destructor
        ~Light();
        
    };

}
