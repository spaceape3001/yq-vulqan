////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Controller.hpp>
#include <tachyon/api/ControllerInfoWriter.hpp>
#include <tachyon/api/ControllerData.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/command/controller/ControlCommand.hpp>
#include <tachyon/command/controller/DisableCommand.hpp>
#include <tachyon/command/controller/EnableCommand.hpp>
#include <tachyon/command/controller/ListenCommand.hpp>
#include <tachyon/command/controller/UncontrolCommand.hpp>
#include <tachyon/command/controller/UnlistenCommand.hpp>
#include <tachyon/command/tachyon/SnoopCommand.hpp>
#include <tachyon/command/tachyon/SubscribeCommand.hpp>
#include <tachyon/command/tachyon/UnsnoopCommand.hpp>
#include <tachyon/command/tachyon/UnsubscribeCommand.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Controller);
YQ_TYPE_IMPLEMENT(yq::tachyon::ControllerID)

namespace yq::tachyon {
    ControllerData::ControllerData() = default;
    ControllerData::~ControllerData() = default;

    /////////////////////////////////////////////////////////////////////////////

    ControllerInfo::ControllerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        set(Type::Controller);
    }
    
    ControllerInfo::~ControllerInfo()
    {
    }

    /////////////////////////////////////////////////////////////////////////////

    ControllerSnap::ControllerSnap() = default;
    ControllerSnap::~ControllerSnap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Controller::Controller(const Param& p) : Tachyon(p)
    {
    }
    
    Controller::~Controller()
    {
    }

    void  Controller::cmd_control(TypedID t)
    {
        mail(new ControlCommand({.source=this, .target=this}, t));
    }

    void  Controller::cmd_enable() 
    { 
        mail(new EnableCommand({.source=this, .target=this}));
    }
    
    void  Controller::cmd_disable() 
    { 
        mail(new DisableCommand({.source=this, .target=this}));
    }
    
    void Controller::cmd_listen(TypedID t)
    {
        mail(new ListenCommand({.source=this, .target=this}, t));
    }

    void Controller::cmd_uncontrol(TypedID t)
    {
        mail(new UncontrolCommand({.source=this, .target=this}, t));
    }

    void Controller::cmd_unlisten(TypedID t)
    {
        mail(new UnlistenCommand({.source=this, .target=this}, t));
    }

    void Controller::on_control_command(const ControlCommand&cmd)
    {
        m_controlled.insert(cmd.tachyon());
        subscribe(cmd.tachyon(), MG::Controlled);
        send(new SubscribeCommand({.target=cmd.tachyon()}, *this, MG::Controller));
        mark();
    }

    void Controller::on_disable_command(const DisableCommand&)
    {
        m_enabled    = false;
        mark();
    }
    
    void Controller::on_enable_command(const EnableCommand&)
    {
        m_enabled    = true;
        mark();
    }

    void Controller::on_listen_command(const ListenCommand& cmd)
    {
        m_listening.insert(cmd.tachyon());
        send(new SnoopCommand({.target=cmd.tachyon()}, *this));
        mark();
    }

    void Controller::on_uncontrol_command(const UncontrolCommand& cmd)
    {
        m_controlled.erase(cmd.tachyon());
        unsubscribe(cmd.tachyon(), MG::Controlled);
        send(new UnsubscribeCommand({.target=cmd.tachyon()}, *this, MG::Controller));
        mark();
    }

    void Controller::on_unlisten_command(const UnlistenCommand& cmd)
    {
        m_listening.erase(cmd.tachyon());
        send(new UnsnoopCommand({.target=cmd.tachyon()}, *this));
        mark();
    }

    void Controller::snap(ControllerSnap&sn) const
    {
        sn.controlled   = m_controlled;
        sn.enabled      = m_enabled;
    }

    Execution Controller::tick(const Context& ctx)
    {
        Tachyon::tick(ctx);
        return {};
    }

    void Controller::init_info()
    {
        auto w = writer<Controller>();
        w.abstract();
        w.description("Abstract Controller");
        w.slot(&Controller::on_control_command);
        w.slot(&Controller::on_disable_command);
        w.slot(&Controller::on_enable_command);
        w.slot(&Controller::on_listen_command);
        w.slot(&Controller::on_uncontrol_command);
        w.slot(&Controller::on_unlisten_command);
        
        auto wt = writer<ControllerID>();
        wt.description("Controller Identifier");
        wt.set(Meta::Flag::ID);
    }
}
