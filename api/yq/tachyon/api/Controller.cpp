////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Controller.hpp"
#include "ControllerInfoWriter.hpp"
#include <yq/tachyon/api/ControllerBind.hpp>
#include <yq/tachyon/api/ControllerData.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/commands/ControllerControlCommand.hpp>
#include <yq/tachyon/commands/ControllerDisableCommand.hpp>
#include <yq/tachyon/commands/ControllerEnableCommand.hpp>
#include <yq/tachyon/commands/ControllerUncontrolCommand.hpp>
#include <yq/tachyon/commands/TachyonSubscribeCommand.hpp>
#include <yq/tachyon/commands/TachyonUnsubscribeCommand.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Controller);

namespace yq::tachyon {
    ControllerBind::ControllerBind(Controller* v) : m_controller(v ? v -> id() : ControllerID()) 
    {
    }

    //////////////////////////////////////

    ControllerInfo::ControllerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        //set(Flag::CONTROLLER);
    }

    Controller::Controller(const Param& p) : Tachyon(p)
    {
    }
    
    Controller::~Controller()
    {
    }

    PostAdvice    Controller::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const ControllerBind* p = dynamic_cast<const ControllerBind*>(&pp)){
            if(p->controller() != id())
                return REJECT;
        }
        return {};
    }

    void  Controller::cmd_control(TachyonID t)
    {
        mail(new ControllerControlCommand(this, t));
    }

    void  Controller::cmd_enable() 
    { 
        mail(new ControllerEnableCommand(this));
    }
    
    void  Controller::cmd_disable() 
    { 
        mail(new ControllerDisableCommand(this));
    }
    
    void Controller::cmd_uncontrol(TachyonID t)
    {
        mail(new ControllerUncontrolCommand(this, t));
    }

    void Controller::on_control_command(const ControllerControlCommand&cmd)
    {
        m_controlled.insert(cmd.tachyon());
        subscribe(cmd.tachyon(), MG::Controlled);
        send(new TachyonSubscribeCommand(cmd.tachyon(), id(), MG::Controller), cmd.tachyon());
        mark();
    }

    void Controller::on_disable_command(const ControllerDisableCommand&)
    {
        m_enabled    = false;
        mark();
    }
    
    void Controller::on_enable_command(const ControllerEnableCommand&)
    {
        m_enabled    = true;
        mark();
    }

    void Controller::on_uncontrol_command(const ControllerUncontrolCommand&cmd)
    {
        m_controlled.erase(cmd.tachyon());
        unsubscribe(cmd.tachyon(), MG::Controlled);
        send(new TachyonUnsubscribeCommand(cmd.tachyon(), id(), MG::Controller), cmd.tachyon());
        mark();
    }

    void Controller::snap(ControllerSnap&sn) const
    {
        sn.controlled   = m_controlled;
        sn.enabled      = m_enabled;
    }

    Execution Controller::tick(Context& ctx)
    {
        Tachyon::tick(ctx);
        return {};
    }

    void Controller::init_info()
    {
        auto w = writer<Controller>();
        w.abstract();
        w.description("Abstract Controller");
        w.slot(&Controller::on_disable_command);
        w.slot(&Controller::on_enable_command);
    }
}
