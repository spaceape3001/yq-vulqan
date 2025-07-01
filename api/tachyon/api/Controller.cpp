////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Controller.hpp>
#include <tachyon/api/ControllerMetaWriter.hpp>
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

    ControllerMeta::ControllerMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(zName, base, sl)
    {
        set(Type::Controller);
    }
    
    ControllerMeta::~ControllerMeta()
    {
    }

    /////////////////////////////////////////////////////////////////////////////

    ControllerSnap::ControllerSnap() = default;
    ControllerSnap::~ControllerSnap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Controller::Controller(const Param& p) : Tachyon(p), m_enabled(p.enabled)
    {
    }
    
    Controller::~Controller()
    {
    }

    void Controller::_control(TypedID tid)
    {
        m_controlled.insert(tid);
        subscribe(tid, MG::Controlled);
        send(new SubscribeCommand({.target=tid}, *this, MG::Controller));
        mark();
    }

    void Controller::_listen(TypedID tid)
    {
        m_listening.insert(tid);
        send(new SnoopCommand({.target=tid}, *this));
        mark();
    }
    
    void Controller::_uncontrol(all_k)
    {
        if(m_controlled.empty())
            return;
            
        for(TypedID tid : m_controlled){
            unsubscribe(tid, MG::Controlled);
            send(new UnsubscribeCommand({.target=tid}, *this, MG::Controller));
        }
        
        m_controlled.clear();
        mark();
    }

    void Controller::_uncontrol(TypedID tid)
    {
        m_controlled.erase(tid);
        unsubscribe(tid, MG::Controlled);
        send(new UnsubscribeCommand({.target=tid}, *this, MG::Controller));
        mark();
    }

    void Controller::_unlisten(TypedID tid)
    {
        m_listening.erase(tid);
        send(new UnsnoopCommand({.target=tid}, *this));
        mark();
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
        if(cmd.target() != id())
            return ;
        _control(cmd.tachyon());
    }
    
    void Controller::on_disable_command(const DisableCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        m_enabled    = false;
        mark();
    }
    
    void Controller::on_enable_command(const EnableCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        m_enabled    = true;
        mark();
    }

    void Controller::on_listen_command(const ListenCommand& cmd)
    {
        if(cmd.target() != id())
            return;
        _listen(cmd.tachyon());
    }

    void Controller::on_uncontrol_command(const UncontrolCommand& cmd)
    {
        if(cmd.target() != id())
            return;
        _uncontrol(cmd.tachyon());
    }

    void Controller::on_unlisten_command(const UnlistenCommand& cmd)
    {
        if(cmd.target() != id())
            return;
        _unlisten(cmd.tachyon());
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
        wt.constructor(construct_id<Controller>);
        wt.casts<TachyonID>();
    }
}
