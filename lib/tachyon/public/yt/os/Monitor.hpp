////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yt/typedef/monitor.hpp>

namespace yq::tachyon {

    class Monitor;
    
    /*! \brief Monitor Information
    
        Information for monitors.
    */
    class MonitorInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const MonitorInfo*>&    all();
        
        //! Standard constructor for the camera information
        MonitorInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
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

    protected:
    
        void        snap(MonitorSnap&) const;
        //virtual void    receive(const post::PostCPtr&) override;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Monitor(const Param&p = {});
        
        //! Default destructor
        ~Monitor();
    };

}
