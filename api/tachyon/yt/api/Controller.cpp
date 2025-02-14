////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/Controller.hpp>
#include <yt/api/ControllerInfoWriter.hpp>
#include <yt/api/ControllerData.hpp>
#include <yt/api/ID.hpp>
#include <ya/commands/controller/ControlCommand.hpp>
#include <ya/commands/controller/DisableCommand.hpp>
#include <ya/commands/controller/EnableCommand.hpp>
#include <ya/commands/controller/ListenCommand.hpp>
#include <ya/commands/controller/UncontrolCommand.hpp>
#include <ya/commands/controller/UnlistenCommand.hpp>
#include <ya/commands/tachyon/SnoopCommand.hpp>
#include <ya/commands/tachyon/SubscribeCommand.hpp>
#include <ya/commands/tachyon/UnsnoopCommand.hpp>
#include <ya/commands/tachyon/UnsubscribeCommand.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Controller);

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
    }
}
