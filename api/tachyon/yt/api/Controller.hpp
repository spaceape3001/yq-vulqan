////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Tachyon.hpp>
#include <yt/typedef/controller.hpp>

namespace yq::tachyon {

    class Controller;
    class ControlCommand;
    class DisableCommand;
    class EnableCommand;
    class ListenCommand;
    class UncontrolCommand;
    class UnlistenCommand;

    class ControllerInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        ControllerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        virtual ~ControllerInfo();
    };
    
    /*! \brief Controller of Posts/Events/etc
    
        Business of a controller is to translate events/posts/commands into 
        commands for some recipient object.  (ie, a camera controller)
        
        Two ways to hook this up...
        1) Snooping on the recipient
        2) Subscribing to the event producer
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
        
        void        cmd_control(TypedID);
        void        cmd_disable();
        void        cmd_enable();
        void        cmd_listen(TypedID);
        void        cmd_uncontrol(TypedID);
        void        cmd_unlisten(TypedID);
        
    protected:    
        virtual Execution        tick(const Context&) override;

        void                snap(ControllerSnap&) const;

        Controller(const Param& p={});

    private:
        
        std::set<TachyonID> m_controlled;
        std::set<TachyonID> m_listening;
        bool                m_enabled   = true;
        bool                m_destroyed = false;
        
        void    on_control_command(const ControlCommand&);
        void    on_disable_command(const DisableCommand&);
        void    on_enable_command(const EnableCommand&);
        void    on_listen_command(const ListenCommand&);
        void    on_uncontrol_command(const UncontrolCommand&);
        void    on_unlisten_command(const UnlistenCommand&);
    };

}

YQ_TYPE_DECLARE(yq::tachyon::ControllerID)
