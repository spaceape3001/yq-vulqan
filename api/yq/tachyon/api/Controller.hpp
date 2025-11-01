////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/controller.hpp>

namespace yq::tachyon {

    class Controller;
    class ControlCommand;
    class DisableCommand;
    class EnableCommand;
    class ListenCommand;
    class UncontrolCommand;
    class UnlistenCommand;

    class ControllerMeta : public TachyonMeta {
    public:
        template <typename C> class Writer;

        ControllerMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        virtual ~ControllerMeta();
    };
    
    /*! \brief Controller of Posts/Events/etc
    
        Business of a controller is to translate events/posts/commands into 
        commands for some recipient object.  (ie, a camera controller)
        
        Two ways to hook this up...
        1) Snooping on the recipient
        2) Subscribing to the event producer
    */
    class Controller : public Tachyon {
        YQ_TACHYON_META(ControllerMeta)
        YQ_TACHYON_DATA(ControllerData)
        YQ_TACHYON_SNAP(ControllerSnap)
        YQ_TACHYON_DECLARE(Controller, Tachyon)
    public:

        struct Param : public Tachyon::Param {
            bool        enabled = true;
            Param(){}
        };
    
        ~Controller();
        
        ControllerID      id() const { return ControllerID(UniqueID::id()); }
        static void init_meta();
        
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

        void            _control(TypedID);
        void            _uncontrol(TypedID);
        void            _uncontrol(all_k);
        void            _listen(TypedID);
        void            _unlisten(TypedID);

    private:
        
        std::set<TypedID>   m_controlled;
        std::set<TypedID>   m_listening;
        bool                m_enabled   = true;
        
        void    on_control_command(const ControlCommand&);
        void    on_disable_command(const DisableCommand&);
        void    on_enable_command(const EnableCommand&);
        void    on_listen_command(const ListenCommand&);
        void    on_uncontrol_command(const UncontrolCommand&);
        void    on_unlisten_command(const UnlistenCommand&);
    };

}

YQ_TYPE_DECLARE(yq::tachyon::ControllerID)
