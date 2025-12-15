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
    class SetRangeʷCommand : public RangeCommand {
        YQ_OBJECT_DECLARE(SetRangeʷCommand, RangeCommand)
    public:
        SetRangeʷCommand(const Header&, const RangeD&);
    
        static void init_meta();
        
        const RangeD&  w_range() const { return m_wRange; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRangeʷCommand(const Header&);
        SetRangeʷCommand(const SetRangeʷCommand&, const Header&);
        ~SetRangeʷCommand();

    private:
        RangeD   m_wRange = {};
        
        SetRangeʷCommand(const SetRangeʷCommand&) = delete;
        SetRangeʷCommand(SetRangeʷCommand&&) = delete;
        SetRangeʷCommand& operator=(const SetRangeʷCommand&) = delete;
        SetRangeʷCommand& operator=(SetRangeʷCommand&&) = delete;
    };
}
