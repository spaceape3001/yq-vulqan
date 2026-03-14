////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/RangeCommand.hpp>
#include <yq/math/Range.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetRangeʷDCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeʷDCommand, RangeCommand)
    public:
        SetRangeʷDCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  w_range() const { return m_wRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeʷDCommand(const Header&);
        SetRangeʷDCommand(const SetRangeʷDCommand&, const Header&);
        ~SetRangeʷDCommand();

    private:
        RangeD   m_wRange = {};
        
        SetRangeʷDCommand(const SetRangeʷDCommand&) = delete;
        SetRangeʷDCommand(SetRangeʷDCommand&&) = delete;
        SetRangeʷDCommand& operator=(const SetRangeʷDCommand&) = delete;
        SetRangeʷDCommand& operator=(SetRangeʷDCommand&&) = delete;
    };
}
