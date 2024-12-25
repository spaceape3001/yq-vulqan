////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/typedef/controller.hpp>

namespace yq::tachyon {

    class Controller;
    class ControllerControlCommand;
    class ControllerDisableCommand;
    class ControllerEnableCommand;
    class ControllerListenCommand;
    class ControllerUncontrolCommand;
    class ControllerUnlistenCommand;

    class ControllerInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        ControllerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    };
    
    /*! \brief Controller of Posts/Events/etc
    
        Business of a controller is to translate events/posts/commands into 
        commands for some recipient object.  (ie, a camera controller)
        
        
    */
    class Controller : public Tachyon {
        YQ_TACHYON_INFO(ControllerInfo)
        YQ_TACHYON_DATA(ControllerData)
        YQ_TACHYON_SNAP(ControllerSnap)
        YQ_TACHYON_DECLARE(Controller, Tachyon)
    public:
    
        ~Controller();
        
        ControllerID      id() const { return ControllerID(UniqueID::id()); }
        static void init_info();
        
        bool        enabled() const { return m_enabled; }
        
        void        cmd_control(TachyonID);
        void        cmd_disable();
        void        cmd_enable();
        void        cmd_listen(TachyonID);
        void        cmd_uncontrol(TachyonID);
        void        cmd_unlisten(TachyonID);
        
    protected:    
        virtual Execution        tick(Context&) override;

        void                snap(ControllerSnap&) const;
        virtual PostAdvice  advise(const Post&) const override;

        Controller(const Param& p={});

    private:
        
        std::set<TachyonID> m_controlled;
        std::set<TachyonID> m_listening;
        bool                m_enabled   = true;
        bool                m_destroyed = false;
        
        void    on_control_command(const ControllerControlCommand&);
        void    on_disable_command(const ControllerDisableCommand&);
        void    on_enable_command(const ControllerEnableCommand&);
        void    on_listen_command(const ControllerListenCommand&);
        void    on_uncontrol_command(const ControllerUncontrolCommand&);
        void    on_unlisten_command(const ControllerUnlistenCommand&);
    };

}
