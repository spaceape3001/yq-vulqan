////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/typedef/size2.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/monitor.hpp>

namespace yq::tachyon {

    class Monitor;
    
    /*! \brief Monitor Information
    
        Information for monitors.
    */
    class MonitorInfo : public TachyonMeta {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const MonitorInfo*>&    all();
        
        //! Standard constructor for the camera information
        MonitorInfo(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*! \brief It's a monitor
    */
    class Monitor : public Tachyon {
        YQ_TACHYON_INFO(MonitorInfo);
        YQ_TACHYON_DATA(MonitorData)
        YQ_TACHYON_SNAP(MonitorSnap)
        YQ_TACHYON_DECLARE(Monitor, Tachyon)
    public:    
    
        //  TODO... we'll put anything about multiple viewports here (ie, VR)
    

        static void init_info();

        MonitorID            id() const { return MonitorID(UniqueID::id()); }

        //! Returns the approximate dimensions of the monitor, should *NEVER* change
        virtual Size2MM     dimensions() const;

        virtual Size2D      size() const;
        virtual Vector2D    position() const;
        virtual Vector2F    scale() const;

    protected:
    
        void        snap(MonitorSnap&) const;

        //! Default constructor
        Monitor(const Param&p = {});
        
        //! Default destructor
        ~Monitor();
    };

}
YQ_TYPE_DECLARE(yq::tachyon::MonitorID)
