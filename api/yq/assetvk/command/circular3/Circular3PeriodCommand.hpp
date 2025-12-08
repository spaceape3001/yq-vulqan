////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/assetvk/command/Circular3Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³PeriodCommand : public Circular³Command {
        YQ_OBJECT_DECLARE(Circular³PeriodCommand, Circular³Command)
    public:
    
        static void init_meta();
        Circular³PeriodCommand(const Header&, unit::Second);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        unit::Second    period() const { return m_period; }
        
    protected:
        Circular³PeriodCommand(const Circular³PeriodCommand&, const Header&);
        ~Circular³PeriodCommand();
        
    private:
        unit::Second    m_period;
    
        Circular³PeriodCommand(const Circular³PeriodCommand&) = delete;
        Circular³PeriodCommand(Circular³PeriodCommand&&) = delete;
        Circular³PeriodCommand& operator=(const Circular³PeriodCommand&) = delete;
        Circular³PeriodCommand& operator=(Circular³PeriodCommand&&) = delete;
    };
}
